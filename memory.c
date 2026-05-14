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

int	init_stacks(t_stack *a, t_stack *b, int size)
{
	a->nbr = NULL;
	b->nbr = NULL;
	a->nbr = malloc(size * sizeof(int));
	if (!a->nbr)
		return (1);
	b->nbr = malloc(size * sizeof(int));
	if (!b->nbr)
		return (2);
	a->size = size;
	b->size = 0;
	return (0);
}
