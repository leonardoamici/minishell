/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:42:07 by lamici            #+#    #+#             */
/*   Updated: 2023/02/27 15:42:08 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	x;
	int	check;

	x = 0;
	check = 0;
	while (str1[x] != '\0' && check == 0)
	{
		if (str1[x] == str2[x])
			x++;
		else if (str1[x] < str2[x])
			check = -1;
		else if (str1[x] > str2[x])
			check = 1;
	}
	return (check);
}
