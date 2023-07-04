/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexd_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:33:44 by lamici            #+#    #+#             */
/*   Updated: 2023/06/30 15:34:55 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	prova(int fd, unsigned int n, char format)
{
	if (n >= 16)
	{
		prova(fd, n / 16, format);
		prova(fd, n % 16, format);
	}
	else if (n > 9)
	{
		if (format == 'x')
			n = n + 87;
		else
			n = n + 55;
		write(fd, &n, 1);
	}
	else
	{
		n = n + 48;
		write(fd, &n, 1);
	}
}

int	ft_hexd_fd(int fd, unsigned int n, char format)
{
	unsigned int	x;
	int				y;

	y = 1;
	x = n;
	prova(fd, n, format);
	while (x >= 16)
	{
		x = x / 16;
		y++;
	}
	return (y);
}
