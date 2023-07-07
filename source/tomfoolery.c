/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tomfoolery.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 10:39:16 by lamici            #+#    #+#             */
/*   Updated: 2023/07/07 15:15:42 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_check_env(t_list *my_env)
{
	int	pwd;
	int	user;

	pwd = 0;
	user = 0;
	while (my_env->next)
	{
		if (!ft_strcmp(my_env->name, "PWD"))
			pwd += 1;
		else if (!ft_strcmp(my_env->name, "USER"))
			user += 1;
		my_env = my_env->next;
	}
	if (!pwd)
	{
		ft_new_var(my_env, "PWD=/nfs/homes", 1);
		chdir("/nfs/homes");
	}
	if (!user)
		ft_new_var(my_env, "USER=stupid", 1);
}

int	ft_is_variable_cmd(char *str)
{
	int	check;
	int	i;

	if (!ft_strchr(str, '='))
		return (0);
	check = 1;
	i = 0;
	if (ft_isalpha(str[i]))
	{
		i++;
		while (str[i] != '=' && check == 1)
		{
			if (ft_isalnum(str[i]))
				i++;
			else
				check = 0;
		}
	}
	else
		check = 0;
	return (check);
}

int	ft_check_dir(char *str)
{
	DIR	*test;

	test = opendir(str);
	return (closedir(test) + 1);
}

void	ft_free_node(t_list *node)
{
	free(node->content);
	free(node->name);
	free(node);
}
