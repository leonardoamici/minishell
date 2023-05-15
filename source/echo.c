/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:05:25 by lamici            #+#    #+#             */
/*   Updated: 2023/05/15 16:54:47 by lamici           ###   ########.fr       */
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

int		ft_pwd(int fd)
{
	char *path;

	if(fd == 0)
		;
	path = getenv("PWD");
	printf("%s\n",  path);
}

int		ft_env(char **env, int fd)
{
	int		y;

	y = 0;
	while(env[y])
	{
		ft_putstr_fd(ft_strjoin(env[y], "\n"), fd);
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