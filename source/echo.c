/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:05:25 by lamici            #+#    #+#             */
/*   Updated: 2023/05/16 12:40:18 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_echo(int flag, int fd, char *str)
{
	int		i;

	i = 0;
	while(str[i] != '\0')
	{
		if(i == ft_strlen(str) && flag == 1)
			break;
		write(fd, &str[i], 1);
		i++;
	}
}

int		ft_pwd(char **my_env, int fd)
{
	int		x;
	char 	*path;

	x = 0;
	while(my_env[x])
	{
		if(ft_strncmp(my_env[x], "PWD", 3));
		{
			path = my_env[x];
			ft_putstr_fd(my_env[x] + 4, fd);
		}
	}
}

int		ft_env(char **my_env, int fd)
{
	int		y;

	y = 0;
	while(my_env[y])
	{
		ft_putstr_fd(my_env[y], fd);
		write(fd, "\n", 1);
		y++;
	}
	return(0);
}

void	ft_free_list(t_list *vars)
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

int		ft_exit(t_list *vars, char *str)
{
	ft_free_list(vars);
	free(str);
	exit(0);
}

int		ft_cd(char *str, char **my_env)
{
	int		x;

	x = ft_get_env_addr(my_env, "PWD");
	if(!chdir(str))
	{
		if(str[0] == '/')
		{
			free(my_env[x]);
			my_env[x] = ft_strjoin("PWD=", ft_strdup(str));
		}
		else
			my_env[x] = ft_relative_cd(my_env[x], str);
	}
	//perror(-1);
}