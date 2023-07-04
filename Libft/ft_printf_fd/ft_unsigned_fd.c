/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:52:57 by lamici            #+#    #+#             */
/*   Updated: 2023/06/30 15:35:11 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	prova(int fd, unsigned int n)
{
	if (n >= 10)
	{
		prova(fd, n / 10);
		prova(fd, n % 10);
	}
	else
	{
		n = n + 48;
		write(fd, &n, 1);
	}
}

int	ft_unsigned_fd(int fd, unsigned int n)
{
	long	x;
	int		y;

	y = 1;
	x = n;
	prova(fd, n);
	while (x >= 10)
	{
		x = x / 10;
		y++;
	}
	return (y);
}
