/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:32:01 by lamici            #+#    #+#             */
/*   Updated: 2023/07/07 15:28:04 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit;

void	ft_child_kill(int pid)
{
	static int	pid_to_kill = 0;

	if (pid_to_kill)
	{
		ft_putchar_fd('\0', 0);
		kill(pid_to_kill, SIGKILL);
		pid_to_kill = 0;
		write (1, "\n", 1);
	}
	else if (pid)
		pid_to_kill = pid;
}

void	ft_heredoc_sighandler(int signal)
{
	if (signal == CTRL_C)
	{
		ft_child_kill(0);
		g_exit = 130;
	}
}

int	ft_heredoc_ctrld(char *str, char *delimiter)
{
	if (!str)
	{
		ft_printf_fd(2, "minishell: warning: ");
		ft_printf_fd(2, "here-document at line 1 delimited");
		ft_printf_fd(2, " by end-of-file (wanted `%s')\n", delimiter);
		return (1);
	}
	return (0);
}

void	ft_heredoc_write(char *heredoc_path, char *delimiter)
{
	int		heredoc_fd;
	char	*str;
	int		len;

	heredoc_fd = open(heredoc_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (heredoc_fd == -1)
		return ;
	len = ft_strlen(delimiter);
	while (1)
	{
		ft_putstr_fd("> ", 1);
		str = get_next_line(0);
		if (ft_heredoc_ctrld(str, delimiter))
			break ;
		else if (!ft_strncmp(str, delimiter, len) && str[len] == '\n')
		{
			free(str);
			break ;
		}
		ft_putstr_fd(str, heredoc_fd);
		free(str);
	}
	close(heredoc_fd);
}

int	ft_heredoc(char *delimiter, t_msh *msh)
{
	char	*heredoc_path;
	int		fd;
	int		pid;
	int		status;

	g_exit = 0;
	heredoc_path = ".heredoc";
	unlink(heredoc_path);
	pid = fork();
	ft_child_kill(pid);
	if (!pid)
	{
		ft_heredoc_write(heredoc_path, delimiter);
		ft_free_cmdlst(msh->cmd);
		ft_freevars(msh->my_env);
		exit(1);
	}
	signal(CTRL_C, ft_heredoc_sighandler);
	waitpid(pid, &status, 0);
	if (g_exit == 130)
		return (-3);
	if (!WEXITSTATUS(pid))
		return (-1);
	fd = open(heredoc_path, O_RDONLY);
	return (fd);
}
