/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:43:52 by lamici            #+#    #+#             */
/*   Updated: 2023/05/16 12:48:33 by lamici           ###   ########.fr       */
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
	if(!ft_strcmp(str, "history\n"))
		ft_print_history(hst);
	if(!ft_strncmp(str, "$", 1))
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
	if(!ft_strcmp(str, "vars\n"))
		ft_printlist(temp);
	if(!ft_strcmp(str, "pwd\n"))
		ft_pwd(1, my_env);
	if(!ft_strcmp(str, "env\n"))
		ft_env(my_env, 1);
	if(!ft_strcmp(str, "exit\n"))
		ft_exit(var, str);
	if(!ft_strcmp(str, "cd"))
		ft_cd();
}

int		main(int ac, char **av, char **env)
{
	char	*str;
	char	**my_env;

	str = NULL;
	my_env = ft_dup_env(env, 0, str);
	ac = 0;
	av = 0;
	while(1)
	{
		str = readline("$>");
		ft_handler(str, ft_get_hst(str, 0), my_env);
		add_history(str);
		ft_get_hst(str, 1);
		free(str);
	}
}