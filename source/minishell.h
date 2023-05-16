/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:55:13 by lamici            #+#    #+#             */
/*   Updated: 2023/05/16 15:42:51 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef	struct	s_list
{
	char *content;
	char *name;
	int		exp_check;
	struct s_list *next;
} 				t_list;

//project body
void	ft_handler(char *str, char **hst, char **env);
void	ft_print_history(char **hst);
char	**ft_get_hst(char *str, int	type);
//var managing
t_list	*ft_var_creation(char *var);
//built-ins
	int		ft_pwd(char **my_env, int fd);
	int		ft_exit(t_list *vars, char *str);
	//change directory
		int		ft_cd(char *str, char **my_env);
		char	*ft_relative_cd(char *my_cd, char *str);
	int		ft_env();
//env clone managing
char 	**ft_dup_env(char **old_env, int flag, char *var);
int		ft_get_env_addr(char **my_env, char *str);

#endif