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

static int	outside_range(char **argv)
{
	(void)argv;
	return (0);
}

static int	has_dupes(char **argv)
{
	(void)argv;
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

int	invalid_input(char **argv)
{
	if (no_digits(argv) || outside_range(argv) || has_dupes(argv))
		return (1);
	return (0);
}
