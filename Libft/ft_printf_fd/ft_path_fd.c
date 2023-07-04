/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:55:20 by lamici            #+#    #+#             */
/*   Updated: 2023/06/30 15:33:46 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	prova(int fd, unsigned long int n)
{
	if (n >= 16)
	{
		prova(fd, n / 16);
		prova(fd, n % 16);
	}
	else
	{
		if (n > 9)
			n = n + 87;
		else
			n = n + 48;
		write(fd, &n, 1);
	}
}

int	ft_path_fd(int fd, unsigned long int n)
{
	unsigned long int		x;
	int						y;

	y = 1;
	x = n;
	if (x == 0)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	write(fd, "0x", 2);
	prova(fd, n);
	while (x >= 16)
	{
		x = x / 16;
		y++;
	}
	return (y + 2);
}
