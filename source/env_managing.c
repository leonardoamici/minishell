/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_managing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:43:50 by lamici            #+#    #+#             */
/*   Updated: 2023/06/05 17:44:47 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
