/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:42:07 by lamici            #+#    #+#             */
/*   Updated: 2023/05/17 14:39:45 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *str1, char *str2)
{
	/*int	x;
	int	check;

	x = 0;
	check = 1;
	if(ft_strlen(str1) == ft_strlen(str2))
	{
		while (str1[x] != '\0' && check == 0)
		{
			if (str1[x] == str2[x])
				x++;
			else if (str1[x] < str2[x])
				check = -1;
			else if (str1[x] > str2[x])
				check = 1;
		}
		check = 0;
	}*/
	while(*str1)
	{
		if(*str1 != *str2)
			break ;
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
