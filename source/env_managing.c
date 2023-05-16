/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_managing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:43:50 by lamici            #+#    #+#             */
/*   Updated: 2023/05/16 16:30:38 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_dup_env(char **old_env, int flag, char *var)
{
	int		x;
	char 	**myenv;

	x = 0;
	if(flag == 0)
	{
		myenv = malloc(sizeof(char *) * (ft_matlen(old_env) + 1));
		while(old_env[x])
		{
			myenv[x] = ft_strdup(old_env[x]);
			x++;
		}
		myenv[x] = 0;
	}
	else
	{
		ft_kill_matrix(old_env);
		myenv = malloc(sizeof(char *) * ft_matlen(old_env) + 2);
		while(old_env[x])
		{
			myenv[x] = ft_strdup(old_env[x]);
			x++;
		}
		myenv[x++] =  ft_strdup(var);
		myenv[x] = 0;
	}
	return (myenv);
}

int		ft_get_env_addr(char **my_env, char *str)
{
	int		x;
	int 	len;

	x = 0;
	len = ft_strlen(str);
	while(my_env[x])
	{
		if(!ft_strncmp(my_env[x], str, len))
			return (x);
		x++;	
	}
	return (-1);
}

char	*ft_relative_cd(char *my_cd, char *str)
{
	char *temp;
	char *result;

	temp = ft_strjoin(my_cd, "/");
	result = ft_strjoin(temp, str);
	free(temp);
	free(my_cd);
	return(result);
}