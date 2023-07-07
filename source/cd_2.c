/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:17:34 by lamici            #+#    #+#             */
/*   Updated: 2023/07/07 16:11:08 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_old_pwd(t_list *my_env)
{
	t_list	*temp;
	char	*temp2;

	temp = my_env;
	while (my_env && ft_strcmp(my_env->name, "OLDPWD"))
		my_env = my_env->next;
	while (temp && ft_strcmp(temp->name, "PWD"))
		temp = temp->next;
	if (my_env)
	{
		free(my_env->content);
		my_env->content = ft_strdup(temp->content);
	}
	else
	{
		temp2 = ft_strjoin("OLDPWD=", temp->content);
		while (temp && temp->next)
			temp = temp->next;
		temp->next = ft_var_creation(temp2, 1);
		free(temp2);
	}
}
