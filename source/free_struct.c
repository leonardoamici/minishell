/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:23:05 by abettini          #+#    #+#             */
/*   Updated: 2023/06/28 15:14:11 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//free t_var--------------------------------------------------------------------
void	ft_freevars(t_list *vars)
{
	t_list	*temp;

	while(vars)
	{
		temp = vars->next;
		free(vars->name);
		free(vars->content);
		free(vars);
		vars = temp;
	}
}

void	ft_free_cmdlst(t_prs *cmd)
{
	t_prs	*temp;

	while(cmd)
	{
		temp = cmd->next;
		ft_kill_matrix(cmd->red);
		ft_kill_matrix(cmd->wrd);
		free(cmd);
		cmd = temp;
	}
}
