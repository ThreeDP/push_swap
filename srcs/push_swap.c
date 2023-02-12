/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:27:17 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/12 13:48:22 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac < 2)
		return (0);
	if (errors(&av[1]))
		return (ft_putstr_fd("Error!\n", 2));
	stack = create_stack(&av[1]);
	if ((ac - 1) <= 5)
		bubble_sort(stack, ac - 1);
	else
		radix_sort(stack, ac - 1);
	// while (stack)
	// {
	//     printf("\n%i\n", stack->num);
	//     stack = stack->next;
	// }   
	return (0);
}

