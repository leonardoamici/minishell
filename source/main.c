/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:43:52 by lamici            #+#    #+#             */
/*   Updated: 2023/12/18 14:18:09 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_exit = 0;

void	ft_init(t_msh *msh, t_list *env, t_prs *cmd)
{
	msh->my_env = env;
	msh->cmd = cmd;
	msh->exit = 0;
	msh->std[0] = 0;
	msh->std[1] = 1;
	msh->fd[0] = -2;
	msh->fd[1] = -2;
}

void	ft_launch_shell(t_msh *msh)
{
	char	*str;
	t_list	*vars;

	vars = NULL;
	ft_check_env(msh->my_env);
	ft_sighandler();
	while (!msh->exit)
	{
		str = readline("$>");
		if (!str)
			break ;
		add_history(str);
		if (*str && !ft_check_cmd_err(str))
		{
			ft_parsing(&msh->cmd, str, &msh->my_env);
			ft_pipes(msh->cmd, msh);
			ft_free_cmdlst(msh->cmd);
		}
	}
	ft_freevars(msh->my_env);
}

int	main(int ac, char **av, char **env)
{
	int		x;
	t_list	*my_env;
	t_list	*temp;
	t_msh	msh;
	t_prs	cmd;

	x = 1;
	my_env = ft_var_creation(env[0], 1);
	temp = my_env;
	while (env[x])
	{
		my_env->next = ft_var_creation(env[x], 1);
		my_env = my_env->next;
		x++;
	}
	my_env = temp;
	ft_init(&msh, my_env, &cmd);
	ft_launch_shell(&msh);
	ac = 0;
	av = 0;
	return (0);
}
