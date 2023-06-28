/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_managing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:43:50 by lamici            #+#    #+#             */
/*   Updated: 2023/06/28 15:26:30 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_env(t_list *vars)
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

t_list 	*ft_dup_env(char **old_env)
{
	int		x;
	t_list	*temp;
	t_list	*my_env;

	x = 1;
	my_env = ft_var_creation(old_env[0], 1);
	temp = my_env;
	while(old_env[x])
	{
		my_env = my_env->next;
		my_env = ft_var_creation(old_env[x], 1);
		x++;
	}
	return (temp);
}
static int	ft_count_exp(t_list *vars)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = vars;
	while (tmp)
	{
		if (tmp->exp_check == 1)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

static char	*ft_env_line(t_list *var)
{
	char	*tmp;
	char	*line;

	line = ft_strjoin(var->name, "=");
	tmp = line;
	line = ft_strjoin(tmp, var->content);
	free(tmp);
	return (line);
}

char	**ft_env_matrix(t_list *my_env)
{
	int		i;
	int		count;
	char	**env;
	t_list	*tmp;

	count = ft_count_exp(my_env);
	env = malloc(sizeof(char *) * (count + 1));
	if (!env)
		return (NULL);
	env[count] = NULL;
	tmp = my_env;
	i = 0;
	while (i < count)
	{
		if (my_env->exp_check == 1)
		{
			env[i] = ft_env_line(tmp);
			i++;
		}
		tmp = tmp->next;
	}
	return (env);
}
