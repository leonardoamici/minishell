/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:55:13 by lamici            #+#    #+#             */
/*   Updated: 2023/05/31 17:49:35 by lamici           ###   ########.fr       */
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
char	**ft_handler(char *str, char **hst, t_list **my_env);
void	ft_print_history(char **hst);
char	**ft_get_hst(char *str, int	type);
//var managing
void	ft_new_var(t_list *env, char *var);
t_list	*ft_var_creation(char *var, int check);
//built-ins
void		ft_pwd(t_list *my_env);
int		ft_exit(t_list *vars, char *str);
int		ft_echo(int flag, int fd, char *str);
char	**ft_unset(t_list **vars, char *name);
// change directory
void		ft_cd(char *str, t_list *my_env);
// env
void		ft_env(t_list *my_env);
//env clone managing
t_list	*ft_dup_env(char **old_env);
void	ft_var_check(t_list *my_env, char *var);
//int		ft_get_env_addr(char **my_env, char *str);
void	ft_export(t_list *vars, char *name);
//signals
void	ft_sighandler(void);

void	print_ancestor(void);
void	print_abettini(void);

#endif