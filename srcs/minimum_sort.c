/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:24:47 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/13 16:57:41 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_nums(t_stack *stack)
{
	if (stack->num > (stack->next)->num)
		print_action(SA, stack, swap_a);
}

void	sort_3_nums(t_stack *stack)
{
	int	max;

	max_num(stack, &max);
	if (max == 0)
		print_action(RA, stack, rotate_a);
	else if (max == 1)
		print_action(RRA, stack, reverse_rotate_a);
	if (stack->num > (stack->next)->num)
		print_action(SA, stack, swap_a);
}

void	sort_4_nums(t_stack *stack)
{
	if (stack->num < (stack->next)->num)
		;
	else if (stack->num < ((stack->next)->next)->num)
		print_action(SA, stack, swap_a);
	else if (stack->num < (((stack->next)->next)->next)->num)
	{
		print_action(SA, stack, swap_a);
		print_action(RA, stack, rotate_a);
		print_action(SA, stack, swap_a);
		print_action(RRA, stack, reverse_rotate_a);
	}
	else
		print_action(RA, stack, rotate_a);
}

void	sort_5_nums(t_stack *stack)
{
	int	find;
	int	lj;

	lmax_num(stack, &lj, max_num(stack, &find));
	if (closer(find) > closer(lj))
		find = lj;
	return_max(stack, find, 3, 4);
	print_action2(PB, &stack, push_b);
	max_num(stack, &find);
	return_max(stack, find, 2, 3);
	print_action2(PB, &stack, push_b);
	sort_3_nums(stack);
	if ((stack->back)->num < ((stack->back)->back)->num)
		print_action(SB, stack, swap_b);
	print_action2(PA, &stack, push_a);
	print_action2(PA, &stack, push_a);
	print_action(RA, stack, rotate_a);
	print_action(RA, stack, rotate_a);
}

void	minimum_sort(t_stack *stack, int items)
{
	t_stack	*tail;

	tail = stack;
	if (items == 2)
		sort_2_nums(stack);
	if (items == 3)
		sort_3_nums(stack);
	if (items == 4)
	{
		while (tail->next)
			tail = tail->next;
		print_action2(PB, &stack, push_b);
		sort_3_nums(stack);
		print_action2(PA, &stack, push_a);
		sort_4_nums(stack);
	}
	if (items == 5)
	{
		sort_5_nums(stack);
	}
}
