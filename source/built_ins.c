/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:05:25 by lamici            #+#    #+#             */
/*   Updated: 2023/05/31 17:48:29 by lamici           ###   ########.fr       */
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

void	ft_pwd(t_list *my_env)
{
	t_list	*temp;

	temp = my_env;
	while(temp)
	{
		if(!ft_strncmp(temp->name, "PWD", 3))
		{
			printf("%s=%s\n", temp->name, temp->content);
			break;
		}
		else
			temp = temp->next;
	}
}

void	ft_env(t_list *my_env)
{
	t_list	*temp;

	temp = my_env;
	while(temp)
	{
		if(temp->exp_check)
			printf("%s=%s\n", temp->name, temp->content);
		temp = temp->next;
	}
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

void	ft_export(t_list *env, char *name)
{
	t_list	*temp;

	temp = env;
	while(temp && (ft_strncmp(name, temp->name, ft_strlen(name))))
		temp = temp->next;
	if(temp)
		temp->exp_check = 1;
}

int		ft_is_var(t_list *var, char *str)
{
	if(!ft_strcmp(var->name, str))
		return(0);
	else
		return(1);
}

char	**ft_unset(t_list **vars, char *name)
{
	int		i;
	t_list	*temp;
	t_list	*temp2;

	i = 0;
	temp = (*vars)->next;
	temp2 = (*vars);
	if(!ft_is_var(*vars, name))
	{
		free((*vars)->name);
		free((*vars)->content);
		free(*vars);
		*vars = temp;
	}
	else
	{
		while(temp)
		{
			if(!ft_is_var(temp, name))
			{
				temp2->next = temp->next;
				free(temp->name);
				free(temp->content);
				free(temp);
				break ;
			}
			temp2 = temp2->next;
			temp = temp->next;
		}
	}
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