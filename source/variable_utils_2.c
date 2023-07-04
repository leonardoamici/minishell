/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:08:54 by lamici            #+#    #+#             */
/*   Updated: 2023/07/04 16:12:20 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_equal_check(char *str)
{
    int     i;
    int     check;

    i = 0;
    check = 0;
    while(str && str[i] && !check)
    {
        if(str[i] == '=')
            check = 1;
        i++;
    }
    return(check);
}