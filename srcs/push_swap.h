/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:24:20 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/09 22:33:51 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/srcs/libft.h"

typedef struct a_stack
{
	int             num;
	char			stack;
	struct a_stack *back;
	struct a_stack *next;
}   t_stack;

t_stack		*create_stack(char **av);
t_stack		*stack_new(int num);
void		clear_stack(t_stack **stack, void (*del)(void *));

// Sort functions
int			find_max_num(t_stack *stack);
void    	radix_sort(t_stack *stack);

// Actions
void    	rotate_a(t_stack *a);
void    	rotate_b(t_stack *b);
void		rotate_ab(t_stack *stack);
void    	reverse_rotate_a(t_stack *a);
void    	reverse_rotate_b(t_stack *b);
void		reverse_rotate_ab(t_stack *stack);
void    	swap_a(t_stack *a);
void    	swap_b(t_stack *b);
void    	swap_ab(t_stack *stack);
void    	push_a(t_stack **stack);
void    	push_b(t_stack **stack);
#endif