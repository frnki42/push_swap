/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki <frnki@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 04:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2026/04/20 16:20:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	init_stacks(t_stack *a, t_stack *b)
{
	a->size = 0;
	b->size = 0;
	a->disorder = 0.0f;
	b->disorder = 0.0f;
	a->top = NULL;
	b->top = NULL;
}

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
