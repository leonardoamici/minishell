/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_1_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:39:29 by gmorelli          #+#    #+#             */
/*   Updated: 2023/07/07 15:30:25 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit;

int	ft_single_node(t_prs *cmd, t_msh *msh, int fd_in, int fd_out)
{
	int	ret;

	ret = ft_redirects(cmd, msh);
	if (!ret)
	{
		ft_choose_redir(msh, fd_in, fd_out);
		ret = ft_execution(cmd->wrd, msh);
	}
	ft_reset_redir(msh);
	return (ret);
}

int	ft_handle_node(t_prs *cmd, t_msh *msh, int fd_in, int fd_out)
{
	int		pid;
	int		exit_code;
	int		ret;

	pid = fork();
	if (!pid)
	{
		if (!ft_redirects(cmd, msh))
		{
			ft_choose_redir(msh, fd_in, fd_out);
			ft_execution(cmd->wrd, msh);
		}
		ft_freevars(msh->my_env);
		ft_free_cmdlst(msh->cmd);
		exit(g_exit);
	}
	waitpid(pid, &exit_code, 0);
	if (WIFEXITED(exit_code))
		g_exit = WEXITSTATUS(exit_code);
	if (WIFSIGNALED(exit_code))
		g_exit = WTERMSIG(exit_code);
	close(fd_in);
	return (g_exit);
}

int	ft_pipes_handler(t_prs *cmd, t_msh *msh, int fd_out)
{
	int	fd[2];

	if (!cmd->next)
	{
		fd[0] = dup(msh->std[0]);
		fd[1] = -2;
	}
	else
	{
		pipe(fd);
		ft_pipes_handler(cmd->next, msh, fd[1]);
	}
	if (fd[1] > -1)
		close(fd[1]);
	return (ft_handle_node(cmd, msh, fd[0], fd_out));
}

int	ft_pipes(t_prs *cmd, t_msh *msh)
{
	int	ret;

	if (!cmd->next)
	{
		ret = ft_single_node(cmd, msh, 0, 1);
	}
	else
	{
		ret = ft_pipes_handler(cmd, msh, 1);
	}
	return (ret);
}
