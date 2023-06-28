/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:05:25 by lamici            #+#    #+#             */
/*   Updated: 2023/06/28 14:45:18 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(char **args)
{
	int		i;
	int		j;
	bool	flag;

	i = 0;
	flag = 0;
	if (*args && !ft_strncmp(*args, "-n", 3))
		flag = ++i;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			write(STDOUT_FILENO, &args[i][j], 1);
			j++;
		}
		i++;
		if (args[i])
			write(STDOUT_FILENO, " ", 1);
	}
	if (!flag)
		write(STDOUT_FILENO, "\n", 1);
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
