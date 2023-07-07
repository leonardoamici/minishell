/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:16:04 by lamici            #+#    #+#             */
/*   Updated: 2023/07/07 15:59:08 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_var_format_check(char *var)
{
	int		x;
	int		check;
	int		equal_check;

	x = 0;
	check = 0;
	equal_check = 1;
	if (var)
	{
		if (!ft_isalpha(var[x]))
			check++;
		while (var[x])
		{
			if (var[x] == '=')
				equal_check--;
			x++;
		}
	}
	return (check + equal_check);
}

t_list	*ft_var_creation(char *var, int check)
{
	int			x;
	int			z;
	t_list		*vars;

	x = 0;
	z = 0;
	vars = malloc(sizeof(t_list));
	while (var[x] && var[x] != '=')
		x++;
	while (var[z])
		z++;
	vars->content = ft_givecontent((z - x - ft_offset(var)), var);
	vars->name = ft_givename(x, var);
	vars->next = NULL;
	if (check)
		vars->exp_check = 1;
	else
		vars->exp_check = 0;
	return (vars);
}

t_list	*ft_new_var(t_list *env, char *var, int exp)
{
	t_list	*temp;
	t_list	*vars;

	temp = env;
	while (temp->next)
		temp = temp->next;
	temp->next = ft_var_creation(var, exp);
	return (temp->next);
}

t_list	*ft_var_check(t_list *my_env, char *var)
{
	int			check;
	t_list		*temp;
	t_list		*tvar;

	check = 0;
	temp = my_env;
	tvar = ft_var_creation(var, 0);
	while (temp)
	{
		if (!ft_strcmp(tvar->name, temp->name) && ++check)
			break ;
		temp = temp->next;
	}
	if (check)
	{
		free(temp->content);
		temp->content = ft_strdup(tvar->content);
		if (temp->exp_check == 2)
			temp->exp_check = 1;
	}
	else
		temp = ft_new_var(my_env, var, 0);
	ft_free_node(tvar);
	return (temp);
}
