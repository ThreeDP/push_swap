/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:10:07 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/11 19:26:50 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_signdetect(int c, int *pos)
{	
	if (c == '-')
		return (*pos += 1, -1);
	else if (c == '+')
		return (*pos += 1, 1);
	return (1);
}

ssize_t	ft_atoi(const char *nptr)
{
	int		pos;
	ssize_t	nbr;
	int		sign;

	pos = 0;
	while (ft_isspace(nptr[pos]))
		pos++;
	sign = ft_signdetect(nptr[pos], &pos);
	nbr = 0;
	while (ft_isdigit(nptr[pos]))
	{
		nbr *= 10;
		nbr += (nptr[pos] - '0');
		pos++;
	}
	return (nbr * sign);
}
