/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:03:19 by lamici            #+#    #+#             */
/*   Updated: 2023/05/31 11:59:19 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_go_back(char *my_pwd)
{
	int		x;
	int		z;
	char	*new_pwd;

	x = ft_strlen(my_pwd);
	while(my_pwd[x] != '/')
		x--;
	new_pwd = malloc(sizeof(char) * x + 1);
	z = 0;
	while(z < x)
	{
		new_pwd[z] = my_pwd[z];
		z++;
	}
	new_pwd[z] = '\0';
	free(my_pwd);
	return (new_pwd);
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

void		ft_cd(char *str, t_list	*my_env)
{
	char	*temp;
	char	**moves;
	int		i;

	i = 0;
	while(ft_strncmp(my_env->name, "PWD", 4))
		my_env = my_env->next;
	if(!chdir(str))
	{
		if(str[0] == '/')
		{
			free(my_env->content);
			my_env->content = ft_strdup(str);
		}
		else
		{
			moves = ft_split(str, '/');
			while(moves[i])
			{
				if (moves[i][0] == '.' && moves[i][1] == '.')
					my_env->content = ft_go_back(my_env->content);
				else if(moves[i][0] == '.' && !moves[i][1])
					;
				else
					my_env->content = ft_relative_cd(my_env->content, moves[i]);
				i++;
			}
		}
		ft_kill_matrix(moves);
	}
	else
		perror("Error");
}