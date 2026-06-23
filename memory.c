/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjankovics <bjankovics@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 04:20:42 by bjankovics        #+#    #+#             */
/*   Updated: 2026/06/23 00:00:00 by bjankovics       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	convert_str(char *str, long *nbr)
{
	int	sign;

	if (ft_strlen(str) > 11)
		return (1);
	sign = 1;
	*nbr = 0;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign = -sign;
	while (*str >= '0' && *str <= '9')
		*nbr = *nbr * 10 + *str++ - '0';
	*nbr = *nbr * sign;
	if (*nbr != (int)*nbr)
		return (1);
	return (0);
}

t_node	*new_node(t_node *top, char *str)
{
	t_node	*new;
	long	nbr;

	if (convert_str(str, &nbr))
		return (NULL);
	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->nbr = (int)nbr;
	new->prev = NULL;
	new->next = top;
	if (top)
		top->prev = new;
	return (new);
}

void	free_nodes(t_node *top)
{
	t_node	*tmp;

	while (top)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
}

int	fill_a(t_stack *a, char **argv, int size)
{
	t_node	*tmp;

	while (size--)
	{
		tmp = new_node(a->top, argv[size]);
		if (!tmp)
			return (free_nodes(a->top), 1);
		a->top = tmp;
		a->size++;
	}
	return (0);
}
