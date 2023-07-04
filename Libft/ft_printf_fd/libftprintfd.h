/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintfd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:09:05 by lamici            #+#    #+#             */
/*   Updated: 2023/06/30 15:25:22 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTFD_H
# define LIBFTPRINTFD_H
# include <stdarg.h>
# include <unistd.h>

int		ft_char_fd(int fd, int c);
int		ft_digit_fd(int fd, int n);
int		ft_hexd_fd(int fd, unsigned int n, char format);
int		ft_path_fd(int fd, unsigned long int n);
int		ft_printf_fd(int fd, const char *str, ...);
int		ft_string_fd(int fd, char *str);
int		ft_unsigned_fd(int fd, unsigned int n);
int		ft_matrix_fd(int fd, char **mat);

#endif
