/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:24:20 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/04 20:10:49 by dapaulin         ###   ########.fr       */
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
	struct a_stack *back;
	struct a_stack *next;
}   t_stack;

t_stack		*create_stack(char **av);
t_stack		*stack_new(int num);

#endif