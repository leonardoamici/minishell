/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:43:52 by lamici            #+#    #+#             */
/*   Updated: 2023/06/05 17:46:42 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_handler(char *str, char **hst, t_list **my_env)
{
	int		i;
	
	i = 0;
	if (!ft_strncmp(str, "history", 7))
		ft_print_history(hst);
	else if(!ft_strcmp(str, "vars"))
		ft_printlist(*my_env);
	else if(!ft_strcmp(str, "pwd"))
		ft_pwd(*my_env);
	else if(!ft_strcmp(str, "env"))
		ft_env(*my_env);
    else if(!ft_strcmp(str, "exit"))
    	ft_exit(*my_env, str);
	else if(!ft_strncmp(str, "cd ", 2))
		ft_cd(str + 3, *my_env);
	else if(!ft_strncmp(str, "echo", 5))
		ft_echo(0, 1, str + 5);
	else if(!ft_strncmp(str, "export", 6))
		ft_export(*my_env, str + 7);
	else if(!ft_strncmp(str, "ancestor", 8))
		print_ancestor();
	else if(!ft_strncmp(str, "abettini", 8))
		print_abettini();
	else if(!ft_strncmp(str, "clear", 6))
		system("clear");
	else if(!ft_strncmp(str, "unset", 5))
		ft_unset(my_env, str + 6);
}

void	ft_launch_shell(t_list	**my_env)
{	
	char *str;
	t_list	*vars;
	
	vars = NULL;
	ft_check_env(*my_env);
	str = readline("$>");
	while(str)
	{	
		if (!ft_strncmp(str, "$", 1))
			ft_var_check(*my_env, str + 1);
		else
		{
			ft_handler(str, ft_get_hst(str, 0), my_env);
			add_history(str);
			ft_get_hst(str, 1);
		}
		free(str);
		str = readline("$>");
	}
}

int		main(int ac, char **av, char **env)
{
	int		x;
	t_list	**my_env;
	t_list	*temp;

	x = 1;
	my_env = malloc(sizeof(t_list *));
	(*my_env) = ft_var_creation(env[0], 1);
	temp = (*my_env);
	while(env[x])
	{
		(*my_env)->next = ft_var_creation(env[x], 1);
		(*my_env) = (*my_env)->next;
		x++;
	}
	*my_env = temp;
	ft_launch_shell(my_env);
	ac = 0;
	av = 0;
	return (0);
}
