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
int	has_dupes(t_node *top)
{
	t_node	*cur;
	t_node	*tmp;

	cur = top;
	while (cur)
	{
		tmp = cur->next;
		while (tmp)
		{
			if (cur->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		cur = cur->next;
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
