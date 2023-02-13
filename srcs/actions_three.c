/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:55:10 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/13 16:55:11 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_ab(t_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
}

int	closer(int i)
{
	if (i == 0)
		return (0);
	else if (i == 1)
		return (1);
	else if (i == 5)
		return (1);
	else if (i == 2)
		return (2);
	else if (i == 3)
		return (2);
	return (0);
}

int	max_num(t_stack *stack, int *index)
{
	int	i;
	int	max;

	i = 0;
	max = (1 << 31);
	while (stack)
	{
		if (stack->num > max)
		{
			max = stack->num;
			*index = i;
		}
		i++;
		stack = stack->next;
	}
	return (max);
}

void	lmax_num(t_stack *stack, int *index, int max)
{
	int	j;
	int	lmax;

	j = 0;
	lmax = (1 << 31);
	while (stack)
	{
		if (stack->num > lmax && stack->num != max)
		{
			lmax = stack->num;
			*index = j;
		}
		j++;
		stack = stack->next;
	}
}

void	return_max(t_stack *stack, int find, int middle, int max)
{
	int	i;

	i = 0;
	if (find < middle)
	{
		while (i < find)
		{
			rotate_a(stack);
			ft_putstr_fd("ra\n", 1);
			i++;
		}
	}
	else
	{
		i = max;
		while (i >= find)
		{
			reverse_rotate_a(stack);
			ft_putstr_fd("rra\n", 1);
			i--;
		}
	}
}
