/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:30:48 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/04 20:24:03 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_stack	*stack_new(int num)
{
		t_stack	*head;
		
		head = (t_stack *) malloc(sizeof(t_stack));
		if (!head)
			return (NULL);
		head->num = num;
		head->next = NULL;
		head->back = NULL;
		return (head);
}

t_stack	*create_stack(char **av)
{
	int		i;
	t_stack	*stack;
	t_stack *tmp;
	t_stack *head;

	i = 1;
	stack = stack_new(ft_atoi(av[i]));
	head = stack;
	while (av[++i])
	{
		stack->next = stack_new(ft_atoi(av[i]));
		tmp = stack;
		stack = stack->next;
		stack->back = tmp;
	}
	return (stack);
}