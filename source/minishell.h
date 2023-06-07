/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:55:13 by lamici            #+#    #+#             */
/*   Updated: 2023/06/07 11:12:38 by lamici           ###   ########.fr       */
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
char		**ft_handler(char *str, char **hst, t_list **my_env);
//printing
void		ft_print_history(char **hst);
void		ft_print_list_exported(t_list *vars);
void		ft_printlist(t_list *vars);
void		ft_env(t_list *my_env);
//var managing
t_list		*ft_new_var(t_list *env, char *var, int exp);
t_list		*ft_var_creation(char *var, int check);
int			ft_is_var(t_list *var, char *str);
int			ft_var_format_check(char *var);
//var utils
int			ft_offset(char *str);
char		*ft_givename(int x, char *str);
char		*ft_givecontent(int x, char *str);
//built-ins
void		ft_pwd(t_list *my_env);
int			ft_exit(t_list *vars, char *str);
int			ft_echo(int flag, int fd, char *str);
char		**ft_unset(t_list **vars, char *name);
// change directory
void		ft_cd(char *str, t_list *my_env);
// history
char		**ft_get_hst(char *str, int	type);
//env clone managing
t_list		*ft_dup_env(char **old_env);
t_list		*ft_var_check(t_list *my_env, char *var);
void    	ft_check_env(t_list *my_env);
t_list		*ft_find_var(t_list *vars, char *str);
void		ft_free_env(t_list *vars);
//int		ft_get_env_addr(char **my_env, char *str);
void		ft_export(t_list *vars, char *name);
//signals
void		ft_sighandler(void);

void	print_ancestor(void);
void	print_abettini(void);

#endif