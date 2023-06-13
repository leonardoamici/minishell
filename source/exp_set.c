/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:41:31 by lamici            #+#    #+#             */
/*   Updated: 2023/06/13 15:42:07 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void 	ft_no_eq(t_list *env, char *name)
{
	t_list	*temp;

	temp = env;
	while(temp)
	{
		if(!ft_strcmp(temp->name, name))
			break;
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

void	ft_export(t_list *env, char *name)
{
	t_list	*temp;
	char 	**mat;
	int		eq_check;
	int		i;
	int		y;

	mat = ft_split(name, ' ');
	i = 0;
	y = 0;
	eq_check = 1;
	if (*mat)
	{
		while(mat[y][i] && eq_check)
		{
			if(mat[y][i] == '=')
				eq_check--;
			i++;
		}
		if(eq_check)
			ft_no_eq(env, name);
		else
		{
			while(*mat)
			{
				temp = ft_var_check(env, *mat);
				temp->exp_check = 1;
				mat++;
			}
		}
		y++;
	}
	else
		ft_print_list_exported(env);
//	ft_kill_matrix(mat);
}

char	**ft_unset(t_list **vars, char *name)
{
	int		i;
	t_list	*temp;
	t_list	*temp2;

	i = 0;
	temp = (*vars)->next;
	temp2 = (*vars);
	if(!ft_strcmp((*vars)->name, name))
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
			if(!ft_strcmp(temp->name, name))
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