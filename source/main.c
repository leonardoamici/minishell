/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:43:52 by lamici            #+#    #+#             */
/*   Updated: 2023/05/11 15:51:18 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_printlist(t_list	*vars)
{
	while(vars)
	{
		printf("%s is %s and check is %d\n", vars->name, vars->content, vars->exp_check);
		vars = vars->next;
	}
}

void	ft_handler(char *str, char **hst)
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
}

int		main(void)
{
	char	*str;

	str = NULL;
	while(1)
	{
		write(1, "&>", 2);	
		str = readline(0);
		ft_handler(str, ft_get_hst(str, 0));
		ft_get_hst(str, 1);
		free(str);
	}
}