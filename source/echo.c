/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:05:25 by lamici            #+#    #+#             */
/*   Updated: 2023/05/21 16:42:37 by leo              ###   ########.fr       */
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
	write(1, "\n", 1);
}

int		ft_pwd(char **my_env, int fd)
{
	int		x;
	char 	*path;

	x = 0;
	while(my_env[x])
	{
		if(!ft_strncmp(my_env[x], "PWD=", 4))
		{
			path = my_env[x];
			ft_putstr_fd(my_env[x], fd);
			write(fd, "\n", 1);
			break;
		}
		x++;
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

char	*ft_go_back(char *str, char *my_pwd)
{
	int		x;
	int		z;
	char	*new_pwd;

	x = ft_strlen(my_pwd);
	z = x;
	while(my_pwd[x] != '/')
		x--;
	x--;
	new_pwd = malloc(sizeof(char) * (z - x) + 1);
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

int		ft_cd(char *str, char **my_env)
{
	int		x;
	char	*temp;

	x = ft_get_env_addr(my_env, "PWD");
	if(!chdir(str))
	{
		if(str[0] == '/')
		{
			free(my_env[x]);
			temp = ft_strdup(str);
			my_env[x] = ft_strjoin("PWD=", temp);
			free(temp);
		}
		else if(str[0] == '.' && str[1] == '.' && !str[2])
			my_env[x] = ft_go_back(str, my_env[x]);
		else
			my_env[x] = ft_relative_cd(my_env[x], str);
	}
	else
		perror("Error");
}

/*
int		ft_cat(char *path, t_fds fds)
{
	char *str;

	str = get_next_line(fds.rfd);
	while (str)
	{
		write(fds.wfd, &str, 1);
		str++;
	}
	free(str);
}*/