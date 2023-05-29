/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:55:13 by lamici            #+#    #+#             */
/*   Updated: 2023/05/29 16:23:13 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

typedef	struct	s_list
{
	char *content;
	char *name;
	int		exp_check;
	struct s_list *next;
} 				t_list;

//project body
char	**ft_handler(char *str, char **hst, char **env, t_list **var);
void	ft_print_history(char **hst);
char	**ft_get_hst(char *str, int	type);
//var managing
t_list	*ft_var_creation(char *var);
//built-ins
int		ft_pwd(char **my_env, int fd);
int		ft_exit(t_list *vars, char *str);
int		ft_echo(int flag, int fd, char *str);
char	**ft_unset(char **my_env, t_list **vars, char *name);
// change directory
int		ft_cd(char *str, char **my_env);
// env
int		ft_env();
//env clone managing
char 	**ft_dup_env(char **old_env, int flag, char *var);
int		ft_get_env_addr(char **my_env, char *str);
char 	**ft_export(char **my_env, t_list *vars, char *name);
//signals
void	ft_sighandler(void);

void	print_ancestor(void);
void	print_abettini(void);

#endif