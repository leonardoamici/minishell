/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:55:13 by lamici            #+#    #+#             */
/*   Updated: 2023/05/10 12:43:32 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

void	ft_handler(char *str, char **hst);
void	ft_print_history(char **hst);
char	**ft_get_hst(char *str, int	type);

#endif