/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_managing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:43:50 by lamici            #+#    #+#             */
/*   Updated: 2023/06/07 11:08:43 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_env(t_list *vars)
{
	t_list	*temp;

	temp = vars;
	while(vars)
	{
		free(vars->content);
		free(vars->name);
		vars = temp->next;
		free(temp);
		temp = vars;
	}
}

t_list 	*ft_dup_env(char **old_env)
{
	int		x;
	t_list	*temp;
	t_list	*my_env;

	x = 1;
	my_env = ft_var_creation(old_env[0], 1);
	temp = my_env;
	while(old_env[x])
	{
		my_env = my_env->next;
		my_env = ft_var_creation(old_env[x], 1);
		x++;
	}
	return (temp);
}
