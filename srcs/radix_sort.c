/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:11:26 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/09 23:24:49 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     find_max_num(t_stack *stack)
{
    int     max_num;

    max_num = 0;
    while (stack)
    {
        if (max_num < stack->num)
            max_num = stack->num;
        stack = stack->next;
    }
    return (max_num);
}

int find_max_binary_position(int max_num)
{
    int i;

    i = 0;
    if (max_num < 0)
        return (0);
    while (max_num != 0)
    {
        i++;
        max_num = max_num >> 1;
    }
    return (i);
}

void    radix_sort(t_stack *stack)
{
    int i;
    
    i = find_max_binary_position(find_max_num(stack));
    
}