/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:08:10 by lamici            #+#    #+#             */
/*   Updated: 2023/05/17 09:32:22 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_nothing(int signal)
{
	if (signal)
		;
}

void	ft_newprompt(int signal)
{
	write(1, "\n", 1);
}

void	ft_sighandler(void)
{
	signal(SIGINT, ft_newprompt);
	signal(SIGQUIT, ft_nothing);
}