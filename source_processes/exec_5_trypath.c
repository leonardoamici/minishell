/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_5_trypath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:15:26 by lamici            #+#    #+#             */
/*   Updated: 2023/07/04 14:50:33 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int g_exit;

static char	**ft_get_path(t_list *vars)
{
	char	**arr_paths;
	t_list	*tmp;

	arr_paths = NULL;
	tmp = ft_find_var(vars, "PATH");
	if (tmp)
		arr_paths = ft_split(tmp->content, ':');
	return (arr_paths);
}

static char	*ft_path_join(char *path, char *cmd)
{
	char	*ret;
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	ret = ft_strjoin(tmp, cmd);
	free(tmp);
	return (ret);
}

int	ft_try_path(char **cmd_f, t_msh *msh)
{
	char	**arr_paths;
	char	*cmd_path;
	int		i;

	g_exit = 127;
	arr_paths = ft_get_path(msh->my_env);
	if (arr_paths)
	{
		i = 0;
		while (arr_paths[i] && g_exit == 127)
		{
			cmd_path = ft_path_join(arr_paths[i], cmd_f[0]);
			if (!access(cmd_path, F_OK))
				ft_execute_cmd(cmd_path, cmd_f, msh);
			free(cmd_path);
			i++;
		}
		ft_kill_matrix(arr_paths);
	}
    if(g_exit == 127)
        ft_printf_fd(2, "minishell: %s: command not found\n", *cmd_f);
	return (g_exit);
}