/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:05:25 by lamici            #+#    #+#             */
/*   Updated: 2023/06/07 11:10:52 by lamici           ###   ########.fr       */
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
