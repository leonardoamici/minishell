/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:52:57 by lamici            #+#    #+#             */
/*   Updated: 2023/06/30 15:33:16 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	prova(unsigned int n)
{
	if (n >= 10)
	{
		prova(n / 10);
		prova(n % 10);
	}
	else
	{
		n = n + 48;
		write(1, &n, 1);
	}
}

int	ft_unsigned(unsigned int n)
{
	long	x;
	int		y;

	y = 1;
	x = n;
	prova(n);
	while (x >= 10)
	{
		x = x / 10;
		y++;
	}
	return (y);
}
