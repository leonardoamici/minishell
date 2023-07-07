/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:45:44 by lamici            #+#    #+#             */
/*   Updated: 2023/07/07 15:22:18 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit;

void	ft_env(t_list *my_env)
{
	t_list	*temp;

	g_exit = 0;
	temp = my_env;
	if (!temp)
		g_exit = 1;
	while (temp)
	{
		if (temp->exp_check == 1)
			printf("%s=%s\n", temp->name, temp->content);
		temp = temp->next;
	}
}

void	ft_printlist(t_list	*vars)
{
	while (vars)
	{
		printf("%s\n%s\n", vars->name, vars->content);
		vars = vars->next;
	}
}

void	ft_print_list_exported(t_list *vars)
{
	while (vars)
	{
		if (vars->exp_check == 1)
			printf("declare -x %s=\"%s\"\n", vars->name, vars->content);
		else if (vars->exp_check == 2)
			printf("declare -x %s\n", vars->name);
		vars = vars->next;
	}
}

void	ft_print_history(char **hst)
{
	int		i;

	i = 0;
	while (hst[i])
	{
		printf("%5d %s\n", i + 1, hst[i]);
		i++;
	}
}
