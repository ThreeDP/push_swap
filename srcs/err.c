/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 01:39:58 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/10 02:11:00 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks if a string contains only
digits or signs and returns its length */
int no_num(char *str)
{
    int i;

    i = 0;
    if (!str || !*str)
        return (0);
    if (*str == '-' || *str == '+')
        str++;
    while (str[i])
    {
        if(!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (i);
}
