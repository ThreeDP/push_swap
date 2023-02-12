/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:11:26 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/12 00:17:55 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	find_max_num(t_stack *stack)
{
	int		max_num;

	max_num = 0;
	while (stack)
	{
		if (max_num < stack->index)
			max_num = stack->index;
		stack = stack->next;
	}
	return (max_num);
}

int	find_max_binary_position(int max_num)
{
	int	i;

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

void	define_index(t_stack *stack)
{
	int		how_many;
	t_stack	*cursor;
	t_stack	*head;

	cursor = stack;
	head = stack;
	while (cursor)
	{
		how_many = 0;
		while (stack)
		{
			if (cursor->num > stack->num)
				how_many++;
			stack = stack->next;
		}
		cursor->index = how_many;
		stack = head;
		cursor = cursor->next;
	}
}

void	radix_sort(t_stack *stack, int items)
{
	int		i;
	int		j;
	int		digits;

	i = 0;
	j = items;
	define_index(stack);
	digits = find_max_binary_position(find_max_num(stack));
	while (i < digits)
	{
		j = items;
		while (j)
		{
			if (((stack->index >> i) & 1) == 1)
			{
				rotate_a(stack);
				ft_putstr_fd("ra\n", 1);
			}
			else
			{
				push_b(&stack);
				ft_putstr_fd("pb\n", 1);
			}
			j--;
		}
		while (stack->back)
		{
			push_a(&stack);
			ft_putstr_fd("pa\n", 1);
		}
		i++;
	}
}
