/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:31:45 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/05 12:31:45 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_a(t_stack *a)
{
    int     tmp;
    t_stack *next;

    if (!a->next)
        return ;
    next = a->next;
    tmp = next->num;
    next->num = a->num;
    a->num = tmp;
    ft_putstr_fd("sa\n", 1);
}

void    swap_b(t_stack *b)
{
    int     tmp;
    t_stack *back;

    if (!b->back)
        return ;
    back = b->back;
    tmp = back->num;
    back->num = b->num;
    b->num = tmp;
    ft_putstr_fd("sb\n", 1);
}

void    swap_ab(t_stack *stack)
{
    swap_a(stack);
    swap_b(stack);
    ft_putstr_fd("ss\n", 1);
}

void    push_a(t_stack **stack)
{
    if (!(*stack)->back)
        return ;
    *stack = (*stack)->back;
    ft_putstr_fd("pa\n", 1);
}

void    push_b(t_stack **stack)
{
    if (!(*stack)->next)
        return ;
    *stack = (*stack)->next;
    ft_putstr_fd("pb\n", 1);
}
