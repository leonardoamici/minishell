/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:13:04 by abettini          #+#    #+#             */
/*   Updated: 2023/06/13 15:39:57 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_lst(t_prs *lst)
{
	t_prs		*tmp;
	int		i;
	int		n;

	n = 1;
	printf("\n");
	while (lst)
	{
		printf("NODE [%d]\n", n);
		printf("___words:_________\n");
		i = -1;
		while (lst->wrd[++i])
			printf("%s\n", lst->wrd[i]);
		printf("___redirects:_____\n");
		i = -1;
		while (lst->red[++i])
			printf("%s\n", lst->red[i]);
		printf("__________________\n\n");
		lst = lst->next;
		n++;
	}
}
