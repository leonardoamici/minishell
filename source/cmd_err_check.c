/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_err_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:10:50 by gmorelli          #+#    #+#             */
/*   Updated: 2023/07/10 14:32:34 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_syntax(char *str)
{
	char	*err_msg;

	err_msg = "minishell: syntax error near unexpected token ";
	if (ft_max_consec_char(str, '|') > 1)
		return (ft_printf_fd(2, "%s `|'\n", err_msg) * 0 + 1);
	if (ft_max_consec_char(str, '>') > 2)
		return (ft_printf_fd(2, "%s`>'\n", err_msg) * 0 + 1);
	if (ft_max_consec_char(str, '<') > 2)
		return (ft_printf_fd(2, "%s`<'\n", err_msg) * 0 + 1);
	if (ft_check_weird_1(str))
		return (ft_printf_fd(2, "minishell: syntax error\n") * 0 + 1);
	if (ft_check_weird_2(str, '|'))
		return (ft_printf_fd(2, "%s`|'\n", err_msg) * 0 + 1);
	if (ft_check_weird_3(str, '>'))
		return (ft_printf_fd(2, "%s`>'\n", err_msg) * 0 + 1);
	if (ft_check_weird_3(str, '<'))
		return (ft_printf_fd(2, "%s`<'\n", err_msg) * 0 + 1);
	return (0);
}

int	ft_no_cmd_b4_pipe_check(char *str)
{
	int		i;
	int		check;
	char	*err_msg;

	err_msg = "minishell: syntax error near unexpected token ";
	check = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '|')
		return (ft_printf_fd(2, "%s`|'\n", err_msg) * 0 + 1);
	return (0);
}

int	ft_stat_update(int stat, char c)
{
	if (stat != 1 && c == '\"')
		stat = 2 - stat;
	else if (stat != 2 && c == '\'')
		stat = 1 - stat;
	return (stat);
}

int	ft_check_cmd_err(char *str)
{
	int	i;
	int	stat;

	stat = 0;
	i = 0;
	if (ft_no_cmd_b4_pipe_check(str))
		return (1);
	while (str[i])
	{
		stat = ft_stat_update(stat, str[i]);
		if (!stat && (str[i] == '\'' || str[i] == '\"'))
			i++;
		if (!stat)
		{
			if (ft_syntax(&str[i]))
				return (1);
			else
				while (!stat && str[i])
					stat = ft_stat_update(stat, str[i++]);
		}
		else
			i++;
	}
	return (0);
}
