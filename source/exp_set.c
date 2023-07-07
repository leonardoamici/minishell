/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:41:31 by lamici            #+#    #+#             */
/*   Updated: 2023/07/07 15:21:13 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit;

void	ft_no_eq(t_list *env, char *name)
{
	t_list	*temp;

	temp = env;
	while (temp)
	{
		if (!ft_strcmp(temp->name, name))
			break ;
		temp = temp->next;
	}
	if (temp && temp->exp_check == 2)
		return ;
	if (temp)
		temp->exp_check = 1;
	else
	{
		temp = ft_new_var(env, name, 0);
		temp->exp_check = 2;
	}
}

void	ft_export(t_list *env, char **mat)
{
	t_list	*temp;
	int		i;

	i = 0;
	g_exit = 0;
	if (!*mat)
		ft_print_list_exported(env);
	while (mat && *mat)
	{
		if (ft_var_name_check(*mat, 1))
		{
			ft_printf_fd(2, "minishell:`%s' : not a valid identifier", *mat);
			g_exit = 1;
		}
		else if (!ft_equal_check(*mat))
			ft_no_eq(env, *mat);
		else
		{
			temp = ft_var_check(env, *mat);
			temp->exp_check = 1;
		}
		mat++;
	}
}

static void	ft_unset_var(t_list **vars, char *name)
{
	t_list	*temp;
	t_list	*temp2;

	temp = (*vars)->next;
	temp2 = (*vars);
	if (!ft_strcmp((*vars)->name, name))
	{
		ft_free_node(*vars);
		*vars = temp;
	}
	else
	{
		while (temp)
		{
			if (!ft_strcmp(temp->name, name))
			{
				temp2->next = temp->next;
				ft_free_node(temp);
				break ;
			}
			temp2 = temp2->next;
			temp = temp->next;
		}
	}
}

static int	ft_unset_check(char *str)
{
	int	i;

	i = 0;
	g_exit = 0;
	if (ft_isalpha(str[i]))
	{
		i++;
		while (str[i] && !g_exit)
		{
			if (ft_isalnum(str[i]))
				i++;
			else
				g_exit = 1;
		}
	}
	else
		g_exit = 1;
	if (g_exit)
		return (printf("minishell: unset: `%s': not a valid identifier\n", str));
	else
		return (0);
}

void	ft_unset(t_list **my_env, char **args)
{
	int	i;
	int	ret;

	ret = 0;
	if (args && *args)
	{
		i = 0;
		while (args[i])
		{
			if (!ft_unset_check(args[i]))
				ft_unset_var(my_env, args[i]);
			i++;
		}
	}
}
