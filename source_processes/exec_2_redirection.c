/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_2_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:11:01 by abettini          #+#    #+#             */
/*   Updated: 2023/07/07 15:28:40 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_choose_redir(t_msh *msh, int fd_in, int fd_out)
{
	if (msh->fd[0] > -1)
		dup2(msh->fd[0], 0);
	else if (msh->fd[0] == -2)
		dup2(fd_in, 0);
	if (msh->fd[1] > -1)
		dup2(msh->fd[1], 1);
	else if (msh->fd[1] == -2)
		dup2(fd_out, 1);
}

void	ft_reset_redir(t_msh *msh)
{
	if (msh->fd[0] > -1)
		close(msh->fd[0]);
	msh->fd[0] = -2;
	dup2(msh->std[0], 0);
	if (msh->fd[1] > -1)
		close(msh->fd[1]);
	msh->fd[1] = -2;
	dup2(msh->std[1], 1);
	if (access(".heredoc", R_OK))
		unlink(".heredoc");
}
