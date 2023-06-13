/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:05:25 by lamici            #+#    #+#             */
/*   Updated: 2023/06/13 15:41:52 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_echo(int flag, int fd, char *str)
{
	int		i;

	i = 0;
	while(str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
	if(!flag)
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
			printf("%s\n", temp->content);
			break;
		}
		else
			temp = temp->next;
	}
}

int		ft_exit(t_list *vars, char *str)
{
	ft_free_env(vars);
	free(str);
	exit(0);
}
