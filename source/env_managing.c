/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_managing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:43:50 by lamici            #+#    #+#             */
/*   Updated: 2023/05/31 10:15:44 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_new_var(t_list *env, char *var)
{
	t_list	*temp;
	t_list	*vars;

	temp = env;
	while(temp->next)
		temp = temp->next;
	temp->next = ft_var_creation(var, 0);
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
		//printf("%s\n", my_env->content);
		x++;
	}
	return (temp);
}

/* int		ft_get_env_addr(char **my_env, char *var)
{
	int		x;
	int 	len;
	char	*temp;

	x = 0;
	temp = ft_strjoin(var, "=");
	len = ft_strlen(temp);
	while(my_env[x])
	{
		if(!ft_strncmp(my_env[x], temp, len))
			return (x);
		x++;	
	}
	return (-1);
}
 */