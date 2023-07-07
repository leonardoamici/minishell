/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:08:10 by lamici            #+#    #+#             */
/*   Updated: 2023/07/07 11:53:32 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit;

void	ft_nothing(int signal)
{
	if (signal)
		;
}

void	ft_newprompt(int signal)
{
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_exit = 130;
}

void	ft_sighandler(void)
{
	signal(SIGINT, ft_newprompt);
	signal(SIGQUIT, ft_nothing);
}
