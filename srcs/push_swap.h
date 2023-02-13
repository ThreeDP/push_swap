/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:24:20 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/13 18:08:30 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/srcs/libft.h"

typedef struct a_stack
{
	int				num;
	int				index;
	char			stack;
	struct a_stack	*back;
	struct a_stack	*next;
}					t_stack;

// Moves
# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

// Manipulate stack list
t_stack	*create_stack(char **av);
t_stack	*stack_new(int num);
void	clear_stack(t_stack **stack, void (*del)(void *));
// Radix sort function
int		find_max_num(t_stack *stack);
void	radix_sort(t_stack *stack, int items);
int		find_max_binary_position(int max_num);
void	define_index(t_stack *stack);
// Minimum_sort
void	minimum_sort(t_stack *stack, int items);
// Utils
void	print_action(char *str, t_stack *stack, void (*action)(t_stack *));
void	print_action2(char *str, t_stack **stack, void (*action)(t_stack **));
// Errors
int		no_num(char *str);
int		find_duplicate(char **args, int i);
int		bigger_than_type_int(char *num, int places);
int		errors(char **av);
// Actions 1
void	swap_b(t_stack *b);
void	swap_a(t_stack *a);
void	swap_ab(t_stack *stack);
void	push_a(t_stack **stack);
void	push_b(t_stack **stack);
// Actions 2
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_ab(t_stack *stack);
void	reverse_rotate_a(t_stack *a);
void	reverse_rotate_b(t_stack *b);
// Actions 3
void	reverse_rotate_ab(t_stack *stack);
int		closer(int i);
int		max_num(t_stack *stack, int *index);
void	lmax_num(t_stack *stack, int *index, int max);
void	return_max(t_stack *stack, int find, int middle, int max);
#endif