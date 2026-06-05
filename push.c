/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki <frnki@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 04:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2026/04/20 16:20:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_b(t_data *data)
{
	if (!data->a.top)
		return ;
	data->a.top->prev = data->b.top;
	data->b.top = data->a.top;
	data->a.top = data->a.top->next;
	data->b.top->next = data->b.top->prev;
	data->b.top->prev = NULL;
	if (data->b.top->next)
		data->b.top->next->prev = data->b.top;
	if (data->a.top)
		data->a.top->prev = NULL;
	data->a.size--;
	data->b.size++;
	write(1, "pb\n", 3);
}

void	push_a(t_data *data)
{
	if (!data->b.top)
		return ;
	data->b.top->prev = data->a.top;
	data->a.top = data->b.top;
	data->b.top = data->b.top->next;
	data->a.top->next = data->a.top->prev;
	data->a.top->prev = NULL;
	if (data->a.top->next)
		data->a.top->next->prev = data->a.top;
	if (data->b.top)
		data->b.top->prev = NULL;
	data->b.size--;
	data->a.size++;
	write(1, "pa\n", 3);
}
