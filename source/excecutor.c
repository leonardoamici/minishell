/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excecutor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:38:09 by lamici            #+#    #+#             */
/*   Updated: 2023/06/14 11:15:23 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_executor(char *str)
{
	char *mat[2];
	int		pid;

	pid = getpid();
	mat[0] = "name";
	mat[1] = 0;
	fork();
	if(pid != getpid() && !execve(str, mat, 0))
		;
	else if (pid != getpid())
		perror("Error");
	else
		pause();
}