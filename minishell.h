/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:55:13 by lamici            #+#    #+#             */
/*   Updated: 2023/07/04 16:12:34 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "Libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <dirent.h>

# define CTRL_C SIGINT
# define CTRL_BS SIGQUIT
# define DEBUG printf("prova\n")

typedef	struct	s_list
{
	char *name;
	char *content;
	int		exp_check;
	struct s_list *next;
} 				t_list;

typedef	struct	s_prs
{
	char **wrd;
	char **red;
	struct s_prs	*next;
}				t_prs;

typedef struct s_msh
{
	t_list	*my_env;
	t_prs	*cmd;
	int		fd[2];
	int		std[2];
	int		exit;
}	t_msh;


//liberator
void		ft_freevars(t_list *vars);
void		ft_free_cmdlst(t_prs *cmd);
//err_check
int			ft_check_cmd_err(char *str);
int			ft_max_consec_char(char *str, char c);
int			ft_check_weird_1(char *str);
int			ft_check_weird_2(char *str, char c);
int			ft_check_weird_3(char *str, char c);
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
int			ft_is_variable_cmd(char *str);
//var utils
int			ft_offset(char *str);
char		*ft_givename(int x, char *str);
char		*ft_givecontent(int x, char *str);
int			ft_var_name_check(char *str, int check);
int			ft_equal_check(char *str);
//built-ins
void		ft_pwd(t_list *my_env);
void		ft_exit(t_msh *msh, char **args);
void		ft_echo(char **args);
void		ft_unset(t_list **my_env, char **args);
// change directory
void		ft_cd(t_list *my_env, char **args);
// history
char		**ft_get_hst(char *str, int	type);
//env clone managing
t_list		*ft_dup_env(char **old_env);
t_list		*ft_var_check(t_list *my_env, char *var);
void    	ft_check_env(t_list *my_env);
t_list		*ft_find_var(t_list *vars, char *str);
void		ft_free_env(t_list *vars);
char		**ft_env_matrix(t_list *my_env);
void		ft_export(t_list *env, char **mat);
int			ft_var_name_len(char *str);
//signals
void		ft_sighandler(void);
//parsing
int			ft_is_special(char c);
int			ft_isspace(char c);
void		ft_parsing(t_prs **prs, char *str, t_list **my_env);
char		*ft_get_var_cont(char *var_name, t_list *vars);
void		ft_quotes_vars_cpy(char *line, char *str, t_list *vars);
int			ft_quotes_vars_len(char *str, t_list *vars);
int			ft_char_char_len(char *str, char c);
void		ft_check_expand(t_prs **lst, t_list *vars);
int			ft_red_len(char *str);
int			ft_wrd_len(char *str);
int			ft_red_count(char *str);
int			ft_wrd_count(char *str);
void		ft_print_lst(t_prs *lst);
int			ft_heredoc(char *delimiter, t_msh *msh);
//executor
int			ft_pipes(t_prs *cmd, t_msh *msh);
int			ft_redirects(t_prs *cmd, t_msh *msh);
void		ft_choose_redir(t_msh *msh, int fd_in, int fd_out);
void		ft_reset_redir(t_msh *msh);
int			ft_execution(char **wrd, t_msh *msh);
int			ft_try_path(char **cmd_w_flag, t_msh *msh);
void		ft_execute_cmd(char *cmd_path, char **cmd_w_flag, t_msh *msh);
void		print_ancestor(void);
void		print_abettini(void);

#endif
