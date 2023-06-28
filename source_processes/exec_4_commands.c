/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_4_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:54:25 by lamici            #+#    #+#             */
/*   Updated: 2023/06/28 15:35:21 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	**ft_get_path(t_list *vars)
{
	char	**arr_paths;
	t_list	*tmp;

	arr_paths = NULL;
	tmp = ft_find_var(vars, "PATH");
	if (tmp)
		arr_paths = ft_split(tmp->content, ':');
	return (arr_paths);
}

static void	ft_execute_cmd(char *cmd_path, char **cmd_w_flag, t_list *vars)
{
	char	**env;
	int		pid;
	int		exit_code;

	pid = fork();
	if (!pid)
	{
		env = ft_env_matrix(vars);
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
}

int	ft_try_path(char **cmd_w_flag, t_list *vars)
{
	char	**arr_paths;
	char	*cmd_path;
	char	*add_slash;
	int		i;
	int		check;

	check = 0;
	arr_paths = ft_get_path(vars);
	if (arr_paths)
	{
		i = 0;
		while (arr_paths[i] && !check)
		{
			add_slash = ft_strjoin(arr_paths[i], "/");
			cmd_path = ft_strjoin(add_slash, cmd_w_flag[0]);
			free(add_slash);
			if (!access(cmd_path, F_OK))
			{
				ft_execute_cmd(cmd_path, cmd_w_flag, vars);
				check = 1;
			}
			free(cmd_path);
			i++;
		}
		ft_kill_matrix(arr_paths);
	}
	return (check);
}

void	ft_executable(char **cmd_w_flag, t_list *vars)
{
	if (!access(*cmd_w_flag, F_OK))
	{
		ft_execute_cmd(*cmd_w_flag, cmd_w_flag, vars);
	}
	else if (!ft_try_path(cmd_w_flag, vars))
	{
		ft_putstr_fd("Command not found\n", 2);
	}
}

int	ft_execution(char **wrd, t_msh *msh)
{
	int	ret;

	ret = 0;
	if (!*wrd || !**wrd)
		return (0);
	if (!ft_strncmp(*wrd, "echo", 5))
		ft_echo(&wrd[1]);
	else if (!ft_strncmp(*wrd, "env", 4))
		ft_env(msh->my_env);
	else if (!ft_strncmp(*wrd, "cd", 3))
		ft_cd(msh->my_env, wrd[1]);
	else if (!ft_strncmp(*wrd, "pwd", 4))
		ft_pwd(msh->my_env);
	else if (!ft_strncmp(*wrd, "export", 7))
		ft_export(msh->my_env, wrd[1]);
	else if (!ft_strncmp(*wrd, "unset", 6))
		ft_unset(&msh->my_env, wrd[1]);
	//else if (!ft_strncmp(*wrd, "exit", 5))
	//	ret = ft_exit(msh);
	else if (ft_strchr(*wrd, '=') && *wrd[0] != '=')
	{
		ft_var_check(msh->my_env, *wrd);
		ret = ft_execution(wrd + 1, msh);
	}
	else
		ft_executable(wrd, msh->my_env);
	return (ret);
}
