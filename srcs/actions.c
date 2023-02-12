/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:31:45 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/12 00:13:59 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a)
{
	int		tmp;
	t_stack	*next;

	if (a->next && a->stack == 'a')
	{
		next = a->next;
		tmp = next->num;
		next->num = a->num;
		a->num = tmp;
		tmp = next->index;
		next->index = a->index;
		a->index = tmp;
	}
}

void	swap_b(t_stack *b)
{
	int		tmp;
	t_stack	*back;

	if (!(!b->next && b->stack == 'b'))
		b = b->back;
	if (b->back && b->stack == 'b')
	{
		back = b->back;
		tmp = back->num;
		back->num = b->num;
		b->num = tmp;
		tmp = back->index;
		back->index = b->index;
		b->index = tmp;
	}
}

void	swap_ab(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}

/*Take the first element at the top of stack b
and put it at the top of a.*/
void	push_a(t_stack **stack)
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
void	push_b(t_stack **stack)
{
	if (!(*stack)->next)
		(*stack)->stack = 'b';
	else
	{
		(*stack)->stack = 'b';
		*stack = (*stack)->next;
	}
}
