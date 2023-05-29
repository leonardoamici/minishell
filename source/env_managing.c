/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_managing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:43:50 by lamici            #+#    #+#             */
/*   Updated: 2023/05/29 15:32:56 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_dup_env(char **old_env, int flag, char *var)
{
	int		x;
	char 	**my_env;
	int		i;

	x = 0;
	if(flag == 0)
	{
		my_env = malloc(sizeof(char *) * (ft_matlen(old_env) + 1));
		while(old_env[x])
		{
			my_env[x] = ft_strdup(old_env[x]);
			x++;
		}
		my_env[x] = 0;
	}
	else if(flag == 1)
	{
		my_env = malloc(sizeof(char *) * ft_matlen(old_env) + 2);
		while(old_env[x])
		{
			my_env[x] = ft_strdup(old_env[x]);
			x++;
		}
		my_env[x++] = ft_strdup(var);
		my_env[x] = 0;
		ft_kill_matrix(old_env);
	}
	else if(flag == -1)
	{
		i = ft_get_env_addr(old_env, var);
		if(i != -1)
		{
			my_env = malloc(sizeof(char *) * ft_matlen(old_env));
			while(old_env[x])
			{
				if(x != i)
					my_env[x] = ft_strdup(old_env[x]);
				x++;
			}
			my_env[x] = 0;
			ft_kill_matrix(old_env);
		}
		else
			my_env = old_env;
	}
	return (my_env);
}

int		ft_get_env_addr(char **my_env, char *var)
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
