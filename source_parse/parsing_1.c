/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:03:09 by abettini          #+#    #+#             */
/*   Updated: 2023/12/11 10:15:52 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//removes unnecessary spaces in the redirects
static char	*ft_red_trim(char *str)
{
	char	*tmp;
	int		i;
	int		x;

	i = 0;
	while (str[i] == '>' || str[i] == '<')
		i++;
	x = i;
	while (ft_isspace(str[i]))
		i++;
	tmp = malloc(ft_red_len(str) - (i - x) + 1);
	i = 0;
	while (str[i] == '>' || str[i] == '<')
	{
		tmp[i] = str[i];
		i++;
	}
	x = i;
	while (ft_isspace(str[i]))
		i++;
	ft_strlcpy(&tmp[x], &str[i], ft_wrd_len(&str[i]) + 1);
	return (tmp);
}

//fills the words matrix and the redirects matrix inside the node
static int	ft_fill_cmdlst(t_prs *tmp, char *str, int i)
{
	int		r;
	int		w;

	r = 0;
	w = 0;
	while (str[i] != '|' && str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		else if (str[i] == '>' || str[i] == '<')
		{
			tmp->red[r] = ft_red_trim(&(str[i]));
			i += ft_red_len(&str[i]);
			r++;
		}
		else if (str[i] != '|')
		{
			tmp->wrd[w] = malloc(ft_wrd_len(&str[i]) + 1);
			ft_strlcpy(tmp->wrd[w], &str[i], ft_wrd_len(&str[i]) + 1);
			i += ft_wrd_len(&str[i]);
			w++;
		}
	}
	return (i);
}

static t_prs	*ft_parse_node(void)
{
	t_prs	*parse;

	parse = malloc(sizeof(t_prs));
	parse->next = NULL;
	return (parse);
}

static void	ft_first_split(t_prs **parse, char *str, int i)
{
	t_prs	*tmp;
	int		wc;
	int		rc;

	(*parse) = ft_parse_node();
	tmp = (*parse);
	while (str[i])
	{
		rc = ft_red_count(&str[i]);
		wc = ft_wrd_count(&str[i]);
		tmp->wrd = malloc(sizeof(char *) * (wc + 1));
		tmp->red = malloc(sizeof(char *) * (rc + 1));
		tmp->wrd[wc] = NULL;
		tmp->red[rc] = NULL;
		i = ft_fill_cmdlst(tmp, str, i);
		while (ft_isspace(str[i]) || str[i] == '|')
			i++;
		if (str[i])
		{
			tmp = ft_parse_node();
			tmp->next = *parse;
			(*parse) = tmp;
		}
	}
}

void	ft_parsing(t_prs **prs, char *str, t_list **my_env)
{
	int	i;

	i = 0;
	ft_first_split(prs, str, i);
	ft_check_expand(prs, *my_env);
}
