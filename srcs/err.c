/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 01:39:58 by dapaulin          #+#    #+#             */
/*   Updated: 2023/02/12 00:22:21 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks if a string contains only
digits or signs and returns its length */
int	no_num(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (i);
}

int	find_duplicate(char **args, int i)
{
	int		j;
	size_t	len;
	size_t	len_cmp;

	j = i + 1;
	len = ft_strlen(args[i]);
	while (args[j])
	{
		len_cmp = ft_strlen(args[j]);
		if (len > len_cmp)
			len_cmp = len;
		if (!ft_strncmp(args[i], args[j], len_cmp))
			return (0);
		j++;
	}
	return (1);
}

int	bigger_than_type_int(char *num, int places)
{
	ssize_t	n;

	n = ft_atoi(num);
	if (places > 10)
		return (1);
	else if (n < -(long)((unsigned int)(1 << 31)))
		return (1);
	else if (n > (ssize_t)((unsigned int) ~ (1 << 31)))
		return (1);
	return (0);
}

int	errors(char **av)
{
	int	i;
	int	places;

	i = 0;
	while (av[i])
	{
		places = no_num(av[i]);
		if (!places)
			return (1);
		else if (!find_duplicate(av, i))
			return (2);
		else if (bigger_than_type_int(av[i], places))
			return (3);
		i++;
	}
	return (0);
}
