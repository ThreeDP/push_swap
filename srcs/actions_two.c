/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:46:34 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/12 00:08:53 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Shift up all elements of stack 'a' by 1.
The First element becomes the last one.*/
void	rotate_a(t_stack *a)
{
	int		tmp;
	int		i;
	t_stack	*head;

	head = a;
	tmp = a->num;
	i = a->index;
	while (a->next)
	{
		a = a->next;
		head->num = a->num;
		head->index = a->index;
		head = head->next;
	}
	head->num = tmp;
	head->index = i;
}

/* Shift up all elements of stack 'b' by 1.
The First element becomes the last one.*/
void	rotate_b(t_stack *b)
{
	int		tmp;
	int		i;
	t_stack	*head;

	if (!(!b->next && b->stack == 'b'))
		b = b->back;
	head = b;
	tmp = b->num;
	i = b->index;
	while (b->back)
	{
		b = b->back;
		head->num = b->num;
		head->index = b->index;
		head = head->back;
	}
	head->num = tmp;
	head->index = i;
}

void	rotate_ab(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}

/* Shift down all elements of stack a by 1.
The last element becomes the first one*/
void	reverse_rotate_a(t_stack *a)
{
	int		num;
	int		i;
	int		tmp;
	int		j;
	t_stack	*next;

	next = a->next;
	num = a->num;
	i = a->index;
	j = 0;
	tmp = 0;
	while (next)
	{
		tmp = next->num;
		next->num = num;
		num = tmp;
		j = next->index;
		next->index = i;
		i = j;
		next = next->next;
	}
	a->num = tmp;
	a->index = j;
}

/* Shift down all elements of stack b by 1.
The last element becomes the first one*/
void	reverse_rotate_b(t_stack *b)
{
	int		num;
	int		i;
	int		tmp;
	int		j;
	t_stack	*back;

	if (!(!b->next && b->stack == 'b'))
		b = b->back;
	back = b->back;
	num = b->num;
	i = b->index;
	j = 0;
	tmp = 0;
	while (back)
	{
		tmp = back->num;
		back->num = num;
		num = tmp;
		j = back->index;
		back->index = i;
		i = j;
		back = back->back;
	}
	b->num = tmp;
	b->index = j;
}
