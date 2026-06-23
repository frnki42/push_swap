/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki <frnki@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 04:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2026/04/20 16:20:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	sa(t_data *data)
{
	int	tmp;

	if (!data->a.top || !data->a.top->next)
		return ;
	tmp = data->a.top->nbr;
	data->a.top->nbr = data->a.top->next->nbr;
	data->a.top->next->nbr = tmp;
}

static void	sb(t_data *data)
{
	int	tmp;

	if (!data->b.top || !data->b.top->next)
		return ;
	tmp = data->b.top->nbr;
	data->b.top->nbr = data->b.top->next->nbr;
	data->b.top->next->nbr = tmp;
}

void	swap_a(t_data *data)
{
	sa(data);
	data->bench.sa++;
	write(1, "sa\n", 3);
}

void	swap_b(t_data *data)
{
	sb(data);
	data->bench.sb++;
	write(1, "sb\n", 3);
}

void	swap_both(t_data *data)
{
	sa(data);
	sb(data);
	data->bench.ss++;
	write(1, "ss\n", 3);
}
