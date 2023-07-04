/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:21:06 by lamici            #+#    #+#             */
/*   Updated: 2023/06/30 15:33:58 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_conv(int fd, va_list ap, char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len = ft_char_fd(fd, va_arg(ap, int));
	if (format == 's')
		print_len = ft_string_fd(fd, va_arg(ap, char *));
	if (format == 'p')
		print_len = ft_path_fd(fd, va_arg(ap, unsigned long));
	if (format == 'd' || format == 'i')
		print_len = ft_digit_fd(fd, va_arg(ap, int));
	if (format == 'u')
		print_len = ft_unsigned_fd(fd, va_arg(ap, unsigned int));
	if (format == 'x' || format == 'X')
		print_len = ft_hexd_fd(fd, va_arg(ap, unsigned int), format);
	if (format == 'M')
		print_len = ft_matrix_fd(fd, va_arg(ap, char **));
	if (format == '%')
	{
		write(fd, "%", 1);
		print_len = 1;
	}
	return (print_len);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	int		i;
	int		print_len;
	va_list	ap;

	i = 0;
	print_len = 0;
	va_start(ap, str);
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			print_len += ft_conv(fd, ap, str[i + 1]);
			i++;
		}
		else
		{
			write(fd, &str[i], 1);
			print_len += 1;
		}
		i++;
	}
	va_end(ap);
	return (print_len);
}
