/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:41:22 by lamici            #+#    #+#             */
/*   Updated: 2023/07/04 15:44:35 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int g_exit;

static int	ft_llong_limit_ret(char *str)
{
	int			i;
	long long	res;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9' && i < 18)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

int	ft_llong_limit_check(char *str)
{
	long long	res;
	int			sign;
	int			i;

	sign = 1;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (ft_strlen(&str[i]) < 19)
		return (0);
	else if (ft_strlen(&str[i]) > 19)
		return (1);
	res = ft_llong_limit_ret(&str[i]);
	if (res > LLONG_MAX / 10)
		return (1);
	else if ((sign == 1 && str[i + 18] - '0' < 8) \
		|| (sign == -1 && str[i + 18] - '0' <= 8))
		return (0);
	return (1);
}

int	ft_digit_check(char *str)
{
	int	i;
	int	check;

	check = 0;
	if (str)
	{
		i = 0;
		if (str[i] == '-' || str[i] == '+' || ft_isdigit(str[i]))
			i++;
		else
			return (1);
		while (!check && str[i])
		{
			if (!ft_isdigit(str[i]))
				check = 1;
			i++;
		}
	}
	return (check);
}

void	ft_exit(t_msh *msh, char **args)
{
	unsigned char	ret;

	if (msh->cmd->next)
		msh->exit = 1;
	if (!*args)
		g_exit = 0;
	else if (args[0] && (ft_digit_check(*args) || ft_llong_limit_check(*args)))
	{
		g_exit = 2;
		ft_printf_fd(2, "bash: exit: %s: numeric argument required\n", *args);
	}
	else if (args[0] && args[1])
	{
		g_exit = 1;
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
	}
	else
	{
		g_exit = ft_atoi(*args) % 256;
	}
}