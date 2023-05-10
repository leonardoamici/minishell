/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:43:52 by lamici            #+#    #+#             */
/*   Updated: 2023/05/10 15:30:00 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_handler(char *str, char **hst)
{
	int		i;

	i = 0;
	if(!ft_strcmp(str, "history\n"))
		ft_print_history(hst);
}

int		main(void)
{
	char	*str;

	str = NULL;
	while(1)
	{
		str = readline(0);
		ft_handler(str, ft_get_hst(str, 0));
		ft_get_hst(str, 1);
		free(str);
	}
}