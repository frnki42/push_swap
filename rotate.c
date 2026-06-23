/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki <frnki@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 04:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2026/04/20 16:20:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ra(t_data *data)
{
	if (!data->a.top || !data->a.top->next)
		return ;
	data->a.top->prev = data->a.top->next;
	while (data->a.top->prev->next)
		data->a.top->prev = data->a.top->prev->next;
	data->a.top->prev->next = data->a.top;
	data->a.top = data->a.top->next;
	data->a.top->prev->next = NULL;
	data->a.top->prev = NULL;
}

static void	rb(t_data *data)
{
	if (!data->b.top || !data->b.top->next)
		return ;
	data->b.top->prev = data->b.top->next;
	while (data->b.top->prev->next)
		data->b.top->prev = data->b.top->prev->next;
	data->b.top->prev->next = data->b.top;
	data->b.top = data->b.top->next;
	data->b.top->prev->next = NULL;
	data->b.top->prev = NULL;
}

void	rot_both(t_data *data)
{
	ra(data);
	rb(data);
	data->bench.rr++;
	write(1, "rr\n", 3);
}

void	rot_a(t_data *data)
{
	ra(data);
	data->bench.ra++;
	write(1, "ra\n", 3);
}

void	rot_b(t_data *data)
{
	rb(data);
	data->bench.rb++;
	write(1, "rb\n", 3);
}
