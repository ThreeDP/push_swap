/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:27:17 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/04 20:22:28 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack;
    
    if (ac < 1)
        printf("\nEntra um numero né!\n");
    printf("\nPow meu!\n");
    stack = create_stack(av);
    while (stack)
    {
        printf(" [%i] ", stack->num);
        stack = stack->back;
    }
    return (0);
}