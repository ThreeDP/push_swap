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

    if (a->next && a->stack == 'a')
    {
        next = a->next;
        tmp = next->num;
        next->num = a->num;
        a->num = tmp;
    }
}

void    swap_b(t_stack *b)
{
    int     tmp;
    t_stack *back;

    back = b->next;
    if (!back)
        return ;
    if (!back->next && back->stack == 'b')
        b = b->next;
    if (b->back && b->stack == 'b')
    {
        back = b->back;
        tmp = back->num;
        back->num = b->num;
        b->num = tmp;
    }
}

void    swap_ab(t_stack *stack)
{
    swap_a(stack);
    swap_b(stack->back);
}

/*Take the first element at the top of stack b
and put it at the top of a.*/
void    push_a(t_stack **stack)
{
    if (!(*stack)->back || (*stack)->stack == 'b')
        (*stack)->stack = 'a';
    else
    {
        *stack = (*stack)->back;
        (*stack)->stack = 'a';
    }
}

/*Take the first element at the top of stack a
and put it at the top of b.*/
void    push_b(t_stack **stack)
{
    if (!(*stack)->next)
        (*stack)->stack = 'b';
    else
    {
        (*stack)->stack = 'b';
        *stack = (*stack)->next;
    }
}
