/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:24:47 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/12 14:33:24 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_nums(t_stack *stack)
{
	if (stack->num > (stack->next)->num)
	{
		swap_a(stack);
		ft_putstr_fd("sa\n", 1);
	}
}

void	sort_3_nums(t_stack *stack, t_stack *middle, t_stack *tail)
{
	while (stack->num > tail->num || middle->num > tail->num)
	{
		reverse_rotate_a(stack);
		ft_putstr_fd("rra\n", 1);
		if (stack->num > middle->num)
		{
			swap_a(stack);
			ft_putstr_fd("sa\n", 1);
		}
	}
	if (stack->num > middle->num)
	{
		swap_a(stack);
		ft_putstr_fd("sa\n", 1);
	}
}

void	sort_4_nums(t_stack *stack)
{
	if (stack->num < (stack->next)->num)
		;
	else if (stack->num < ((stack->next)->next)->num)
	{
		swap_a(stack);
		ft_putstr_fd("sa\n", 1);
	}
	else if (stack->num < (((stack->next)->next)->next)->num)
	{
		swap_a(stack);
		ft_putstr_fd("sa\n", 1);
		rotate_a(stack);
		ft_putstr_fd("ra\n", 1);
		swap_a(stack);
		ft_putstr_fd("sa\n", 1);
		reverse_rotate_a(stack);
		ft_putstr_fd("rra\n", 1);
	}
	else
	{
		rotate_a(stack);
		ft_putstr_fd("ra\n", 1);
	}
}

void	sort_5_nums(t_stack *stack)
{
	if (stack->num < (stack->next)->num)
		;
	else if (stack->num < ((stack->next)->next)->num)
	{
		swap_a(stack);
		ft_putstr_fd("sa\n", 1);
	}
	else if (stack->num < (((stack->next)->next)->next)->num)
	{
		swap_a(stack);
		ft_putstr_fd("sa\n", 1);
		rotate_a(stack);
		ft_putstr_fd("ra\n", 1);
		swap_a(stack);
		ft_putstr_fd("sa\n", 1);
		reverse_rotate_a(stack);
		ft_putstr_fd("rra\n", 1);
	}
	else if (stack->num < ((((stack->next)->next)->next)->next)->num)
	{
		reverse_rotate_a(stack);
		ft_putstr_fd("rra\n", 1);
		swap_a(stack);
		ft_putstr_fd("sa\n", 1);
		rotate_a(stack);
		ft_putstr_fd("ra\n", 1);
		rotate_a(stack);
		ft_putstr_fd("ra\n", 1);
	}
	else
	{
		rotate_a(stack);
		ft_putstr_fd("ra\n", 1);
	}
}

void	bubble_sort(t_stack *stack, int items)
{
	t_stack	*tail;

	tail = stack;
	if (items == 2)
		sort_2_nums(stack);
	if (items == 3)
		sort_3_nums(stack, stack->next, (stack->next)->next);
	if (items == 4)
	{
		while (tail->next)
			tail = tail->next;
		push_b(&stack);
		ft_putstr_fd("pb\n", 1);
		sort_3_nums(stack, stack->next, (stack->next)->next);
		push_a(&stack);
		ft_putstr_fd("pa\n", 1);
		sort_4_nums(stack);
	}
	if (items == 5)
	{
		while (tail->next)
			tail = tail->next;
		push_b(&stack);
		ft_putstr_fd("pb\n", 1);
		push_b(&stack);
		ft_putstr_fd("pb\n", 1);
		sort_3_nums(stack, stack->next, (stack->next)->next);
		push_a(&stack);
		ft_putstr_fd("pa\n", 1);
		sort_4_nums(stack);
		push_a(&stack);
		ft_putstr_fd("pa\n", 1);
		sort_5_nums(stack);
	}
}
