/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:47:24 by lamici            #+#    #+#             */
/*   Updated: 2023/06/30 15:34:45 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_stampa(int fd, int n)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_stampa(fd, n / 10);
		ft_stampa(fd, n % 10);
	}
	else
	{
		n = n + 48;
		write(fd, &n, 1);
	}
}

int	ft_digit_fd(int fd, int n)
{
	long			x;
	int				y;

	y = 1;
	x = n;
	ft_stampa(fd, n);
	if (x < 0)
	{
		y++;
		x = -x;
	}
	while (x >= 10)
	{
		x = x / 10;
		y++;
	}
	return (y);
}
