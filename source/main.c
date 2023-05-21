/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:43:52 by lamici            #+#    #+#             */
/*   Updated: 2023/05/21 16:40:35 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_printlist(t_list	*vars)
{
	while(vars)
	{
		printf("%s=%s\n", vars->name, vars->content);
		vars = vars->next;
	}
}

void	ft_handler(char *str, char **hst, char **my_env)
{
	int		i;
	static t_list	*var = NULL;
	static t_list	*temp;

	i = 0;
	if(!ft_strncmp(str, "history", 7))
		ft_print_history(hst);
	else if(!ft_strncmp(str, "$", 1))
	{	
		if(!var)
		{
			var = ft_var_creation(str + 1);
			temp = var;
		}
		else
		{
			var->next = ft_var_creation(str + 1);
			var = var->next;
		}
	}
	else if(!ft_strcmp(str, "vars"))
		ft_printlist(temp);
	else if(!ft_strcmp(str, "pwd"))
		ft_pwd(my_env, 1);
	else if(!ft_strcmp(str, "env"))
		ft_env(my_env, 1);
	else if(!ft_strcmp(str, "exit"))
		ft_exit(var, str);
	else if(!ft_strncmp(str, "cd", 2))
		ft_cd(str + 3, my_env);
	else if(!ft_strncmp(str, "echo", 4))
		ft_echo(0, 1, str + 5);
	else if(!ft_strncmp(str, "export", 6))
		ft_dup_env(my_env, 1, str + 7);
}

int		main(int ac, char **av, char **env)
{
	char	*str;
	char	**my_env;

	my_env = ft_dup_env(env, 0, NULL);
	ft_sighandler();
	ac = 0;
	av = 0;
	str = readline("$>");
	while(str)
	{
		ft_handler(str, ft_get_hst(str, 0), my_env);
		add_history(str);
		ft_get_hst(str, 1);
		free(str);
		str = readline("$>");
	}
}
