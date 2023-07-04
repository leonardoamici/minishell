/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_4_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:54:25 by lamici            #+#    #+#             */
/*   Updated: 2023/07/04 15:38:24 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int g_exit;

int		ft_exit_status(int	exit_code)
{
	if(WIFEXITED(exit_code))
		return(WEXITSTATUS(exit_code));
	else if (WIFSIGNALED(exit_code))
		return(WTERMSIG(exit_code));
}

void	ft_execute_cmd(char *cmd_path, char **cmd_w_flag, t_msh *msh)
{
	char	**env;
	int		pid;
	int		exit_code;

	pid = fork();
	if (!pid)
	{
		env = ft_env_matrix(msh->my_env);
		if (execve(cmd_path, cmd_w_flag, env) == -1)
		{
			free(cmd_path);
			ft_kill_matrix(env);
			exit(EXIT_FAILURE);
		}
		else
			ft_kill_matrix(env);
		exit(0);
	}
	waitpid(pid, &exit_code, 0);
	g_exit = ft_exit_status(exit_code);
}

void	ft_executable(char **cmd_w_flag, t_msh *msh)
{

	DIR	*test;

	test = opendir(*cmd_w_flag);
	if(test)
	{
		closedir(test);
		printf("minishell: %s: permission denied\n", *cmd_w_flag);
	}
	else if (!access(*cmd_w_flag, F_OK))
	{
		if(access(*cmd_w_flag, X_OK | W_OK | R_OK))
		{
			g_exit = 126;
			printf("minishell: %s: permission denied\n", *cmd_w_flag);
		}
		else
			ft_execute_cmd(*cmd_w_flag, cmd_w_flag, msh);
	}
	else if (ft_try_path(cmd_w_flag, msh))
		ft_putstr_fd("Command not found\n", 2);
}


int	ft_execution_pt2(char **wrd, t_msh *msh)
{
	int	ret;

	ret = 0;
	if (!ft_strncmp(*wrd, "cd", 3))
		ft_cd(msh->my_env, &wrd[1]);
	else if (!ft_strncmp(*wrd, "export", 7))
		ft_export(msh->my_env, &wrd[1]);
	else if (!ft_strncmp(*wrd, "unset", 6))
		ft_unset(&msh->my_env, &wrd[1]);
	else if (!ft_strncmp(*wrd, "exit", 5))
		ft_exit(msh, &wrd[1]);
	else
		ft_executable(wrd, msh);
	return (ret);
}

int	ft_execution(char **wrd, t_msh *msh)
{
	int	ret;

	ret = 0;
	while (*wrd && !**wrd)
		wrd++;
	if (!*wrd)
		return (0);
	if (!ft_strncmp(*wrd, "echo", 5))
		ft_echo(&wrd[1]);
	else if (!ft_strncmp(*wrd, "env", 4))
		ft_env(msh->my_env);
	else if (!ft_strncmp(*wrd, "pwd", 4))
		ft_pwd(msh->my_env);
	else if(ft_is_variable_cmd(*wrd))
	{
			g_exit = 0;
			ft_var_check(msh->my_env, *wrd); 
			ret = ft_execution(wrd + 1, msh);
	}
	else
		ft_execution_pt2(wrd, msh);
	return (ret);
}
