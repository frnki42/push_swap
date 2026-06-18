/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki <frnki@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 04:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2026/04/20 16:20:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rra(t_data *data)
{
	if (!data->a.top || !data->a.top->next)
		return ;
	data->a.top->prev = data->a.top->next;
	while (data->a.top->prev->next)
		data->a.top->prev = data->a.top->prev->next;
	data->a.top->prev->prev->next = NULL;
	data->a.top->prev->prev = NULL;
	data->a.top->prev->next = data->a.top;
	data->a.top = data->a.top->prev;
}

static void	rrb(t_data *data)
{
	if (!data->b.top || !data->b.top->next)
		return ;
	data->b.top->prev = data->b.top->next;
	while (data->b.top->prev->next)
		data->b.top->prev = data->b.top->prev->next;
	data->b.top->prev->prev->next = NULL;
	data->b.top->prev->prev = NULL;
	data->b.top->prev->next = data->b.top;
	data->b.top = data->b.top->prev;
}

void	rev_rot_both(t_data *data)
{
	rra(data);
	rrb(data);
	data->bench.rrr++;
	write(1, "rrr\n", 4);
}

void	rev_rot_a(t_data *data)
{
	rra(data);
	data->bench.rra++;
	write(1, "rra\n", 4);
}

void	rev_rot_b(t_data *data)
{
	rrb(data);
	data->bench.rrb++;
	write(1, "rrb\n", 4);
}
