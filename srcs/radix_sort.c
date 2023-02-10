/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:11:26 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/09 22:44:09 by dapaulin         ###   ########.fr       */
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

void    radix_sort(t_stack *stack)
{
    find_max_num(stack);
}