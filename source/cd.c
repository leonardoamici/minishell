/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:03:19 by lamici            #+#    #+#             */
/*   Updated: 2023/07/10 14:23:22 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit;

char	*ft_go_back(char *my_pwd)
{
	int		x;
	int		z;
	char	*new_pwd;

	x = ft_strlen(my_pwd);
	while (my_pwd[x] != '/')
		x--;
	new_pwd = malloc(sizeof(char) * x + 1);
	z = 0;
	while (z < x)
	{
		new_pwd[z] = my_pwd[z];
		z++;
	}
	new_pwd[z] = '\0';
	free(my_pwd);
	return (new_pwd);
}

char	*ft_relative_cd(char *my_cd, char *moves, t_list *my_env)
{
	char	*temp;
	char	*result;

	result = my_env->content;
	if (moves[0] == '.' && moves[1] == '.' && !moves[2])
		result = ft_go_back(my_env->content);
	else if (moves[0] == '.' && !moves[1])
		;
	else
	{
		if (my_cd[ft_strlen(my_cd) - 1] != '/')
			temp = ft_strjoin(my_cd, "/");
		else
			temp = ft_strdup(my_cd);
		result = ft_strjoin(temp, moves);
		free(temp);
		free(my_cd);
	}
	return (result);
}

static void	ft_cd_1_arg(t_list *my_env, char *str)
{
	t_list	*temp;
	char	**moves;
	int		i;

	i = 0;
	temp = my_env;
	while (my_env && ft_strcmp(my_env->name, "PWD"))
		my_env = my_env->next;
	if (!chdir(str) && my_env)
	{
		ft_old_pwd(temp);
		if (str[0] == '/')
		{
			free(my_env->content);
			my_env->content = ft_strdup("/");
		}
		moves = ft_split(str, '/');
		g_exit = 0;
		while (moves[i])
			my_env->content = ft_relative_cd(my_env->content, \
				moves[i++], my_env);
		ft_kill_matrix(moves);
	}
	else
		g_exit = (ft_printf_fd(2, "cd: no such file or directory\n") * 0 + 1);
}

static void	ft_cd_no_args(t_list *my_env)
{
	t_list	*home;

	home = (ft_find_var(my_env, "HOME"));
	if (home)
		ft_cd_1_arg(my_env, home->content);
}

void	ft_cd(t_list *my_env, char **args)
{
	int	ret;

	ret = 1;
	if (args[0] && args[1])
	{
		ft_printf_fd(2, "minishell: cd: too many arguments\n");
		g_exit = 1;
	}
	else if (!args[0] || (args[0][0] == '~' && !args[0][1]))
		ft_cd_no_args(my_env);
	else
		ft_cd_1_arg(my_env, args[0]);
}
