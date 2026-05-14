/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki <frnki@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 04:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2026/04/20 16:20:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	has_dupes(t_stack *a)
{
	int	i;
	int	k;

	i = -1;
	while (++i < a->size)
	{
		k = i;
		while (++k < a->size) 
			if (a->nbr[i] == a->nbr[k])
				return (1);
	}
	return (0);
}

int	no_digits(char **argv)
{
	char	*str;

	while(*argv)
	{
		str = *argv;
		if (*str == '-' || *str == '+')
			str++;
		if (!*str)
			return (1);
		while (*str)
		{
			if (*str < '0' || *str > '9')
				return (1);
			str++;
		}
		argv++;
	}
	return (0);
}
