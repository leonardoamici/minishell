/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:43:52 by lamici            #+#    #+#             */
/*   Updated: 2023/05/29 16:27:07 by lamici           ###   ########.fr       */
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

char	**ft_handler(char *str, char **hst, char **my_env, t_list **var)
{
	int		i;
	
	i = 0;
	if (!ft_strncmp(str, "history", 7))
		ft_print_history(hst);
	else if(!ft_strcmp(str, "vars"))
		ft_printlist(*var);
	else if(!ft_strcmp(str, "pwd"))
		ft_pwd(my_env, 1);
	else if(!ft_strcmp(str, "env"))
		ft_env(my_env, 1);
	else if(!ft_strcmp(str, "exit"))
		ft_exit(*var, str);
	else if(!ft_strncmp(str, "cd ", 2))
		ft_cd(str + 3, my_env);
	else if(!ft_strncmp(str, "echo", 5))
		ft_echo(0, 1, str + 5);
	else if(!ft_strncmp(str, "export", 6))
		my_env = ft_export(my_env, *var, str + 7);
	else if(!ft_strncmp(str, "ancestor", 8))
		print_ancestor();
	else if(!ft_strncmp(str, "abettini", 8))
		print_abettini();
	else if(!ft_strncmp(str, "clear", 6))
		system("clear");
	else if(!ft_strncmp(str, "unset", 5))
		my_env = ft_unset(my_env, var, str + 6);
	return (my_env);
}

t_list	*ft_list_maker(t_list *var, char *str)
{
	t_list	*temp;

	temp = var;
	if(!var)
		var = ft_var_creation(str + 1);
	else
	{
		while(temp->next)
			temp = temp->next;
		temp->next = ft_var_creation(str + 1);
		temp = temp->next;
		temp->next = NULL;
	}
	return(var);
}

void	ft_launch_shell(char **my_env)
{	
	char *str;
	t_list	*vars;
	
	vars = NULL;
	str = readline("$>");
	while(str)
	{	
		if (!ft_strncmp(str, "$", 1))
			vars = ft_list_maker(vars, str);
		else
		{
			my_env = ft_handler(str, ft_get_hst(str, 0), my_env, &vars);
			add_history(str);
			ft_get_hst(str, 1);
		}
		free(str);
		str = readline("$>");
	}
}

int		main(int ac, char **av, char **env)
{
	char	*str;
	char	**my_env;

	my_env = ft_dup_env(env, 0, NULL);
	//ft_sighandler();
	ft_launch_shell(my_env);
	ac = 0;
	av = 0;
}
