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

t_node	*new_node(t_node *top, char *str)
{
	t_node	*new;

	(void)str;
	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->next = top;
	if (top)
		top->prev = new;
	return (new);
}

int	fill_stack(t_stack *a, char **argv, int size)
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
