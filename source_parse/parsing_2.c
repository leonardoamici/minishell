/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:44:04 by abettini          #+#    #+#             */
/*   Updated: 2023/07/07 11:45:01 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_char_char_len(char *str, char c)
{
	int		i;

	i = 0;
	if (str[i] == c)
	{
		i++;
		while (str[i] != c && str[i])
			i++;
		if (str[i])
			i++;
	}
	return (i);
}

//measure the lenght of the redirect
int	ft_red_len(char *str)
{
	int		i;
	bool	end;

	i = 0;
	while (str[i] == '>' || str[i] == '<')
		i++;
	while (ft_isspace(str[i]))
		i++;
	end = 0;
	while (!end)
	{
		i += ft_char_char_len(&str[i], '\'');
		i += ft_char_char_len(&str[i], '\"');
		if (!str[i] || ft_is_special(str[i]) || ft_isspace(str[i]))
			end = 1;
		else
			i++;
	}
	return (i);
}

//calcola la lunghezza della parola
int	ft_wrd_len(char *str)
{
	int		i;
	bool	end;

	i = 0;
	end = 0;
	while (!end)
	{
		i += ft_char_char_len(&str[i], '\'');
		i += ft_char_char_len(&str[i], '\"');
		if (!str[i] || ft_is_special(str[i]) || ft_isspace(str[i]))
			end = 1;
		else
			i++;
	}
	return (i);
}

//conta quanti redirect ci sono
int	ft_red_count(char *str)
{
	int	i;
	int	red_count;

	red_count = 0;
	i = 0;
	while (str[i] != '|' && str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		else if (str[i] == '>' || str[i] == '<')
		{
			red_count += 1;
			i += ft_red_len(&str[i]);
		}
		else
			i += ft_wrd_len(&str[i]);
	}
	return (red_count);
}

//conta quante parole ci sono
int	ft_wrd_count(char *str)
{
	int	i;
	int	wrd_count;

	wrd_count = 0;
	i = 0;
	while (str[i] != '|' && str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		else if (str[i] == '>' || str[i] == '<')
			i += ft_red_len(&str[i]);
		else
		{
			wrd_count += 1;
			i += ft_wrd_len(&(str[i]));
		}
	}
	return (wrd_count);
}
