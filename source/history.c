/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:44:10 by lamici            #+#    #+#             */
/*   Updated: 2023/07/07 11:55:42 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_get_hst(char *str, int type)
{
	static char	*hst[4000];
	static int	i;

	if (!i)
		hst[i] = 0;
	if (type)
	{
		if (hst[i] == 0)
		{
			hst[i] = ft_strdup(str);
			i++;
			hst[i] = NULL;
		}
		return (hst);
	}
	else
		return (hst);
}
