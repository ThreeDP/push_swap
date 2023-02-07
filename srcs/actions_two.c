/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:46:34 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/05 12:46:34 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Shift up all elements of stack 'a' by 1.
The First element becomes the last one.*/
void    rotate_a(t_stack *a)
{
	int		num;
	int		tmp;
	t_stack	*head;

	head = a;
	tmp = a->num;
	while (a->next)
	{
		a = a->next;
		head->num = a->num;
		head = head->next;
	}
	head->num = tmp;
}

/* Shift up all elements of stack 'b' by 1.
The First element becomes the last one.*/
void    rotate_b(t_stack *b)
{
	int		num;
	int		tmp;
	t_stack	*head;

	head = b;
	tmp = b->num;
	while (b->back)
	{
		b = b->back;
		head->num = b->num;
		head = head->back;
	}
	head->num = tmp;
}

void	rotate_ab(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}

void    reverse_rotate_a(t_stack *a)
{
	int		num;
	int		tmp;
	t_stack	*head;

	head = a;
	num = 0;
	tmp = a->num;
	while (a->next)
	{
		num = tmp;
		a = a->next;
		tmp = a->num;
		a->num = num;
	}
	head->num = a->num;
}

void    reverse_rotate_b(t_stack *b)
{
	int		num;
	int		tmp;
	t_stack	*head;

	head = b;
	num = 0;
	tmp = b->num;
	while (b->back)
	{
		num = tmp;
		b = b->back;
		tmp = b->num;
		b->num = num;
	}
	head->num = b->num;
}

void	reverse_rotate_ab(t_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
}
