/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:49:28 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/13 16:57:54 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_action(char *str, t_stack *stack, void (*action)(t_stack *))
{
	action(stack);
	ft_putstr_fd(str, 1);
}

void	print_action2(char *str, t_stack **stack, void (*action)(t_stack **))
{
	action(stack);
	ft_putstr_fd(str, 1);
}
