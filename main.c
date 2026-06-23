/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjankovics <bjankovics@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 04:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2026/06/23 00:00:00 by bjankovics       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	bench_print_line(char *name, int count)
{
	if (!count)
		return ;
	ft_putstr_fd(name, 1);
	ft_putnbr_fd(count, 1);
	ft_putchar_fd('\n', 1);
}

static void	print_bench(t_bench *b)
{
	bench_print_line("sa: ", b->sa);
	bench_print_line("sb: ", b->sb);
	bench_print_line("ss: ", b->ss);
	bench_print_line("pa: ", b->pa);
	bench_print_line("pb: ", b->pb);
	bench_print_line("ra: ", b->ra);
	bench_print_line("rb: ", b->rb);
	bench_print_line("rr: ", b->rr);
	bench_print_line("rra: ", b->rra);
	bench_print_line("rrb: ", b->rrb);
	bench_print_line("rrr: ", b->rrr);
}

static void	dispatch(t_data *data)
{
	if (data->strategy == SIMPLE)
		sort_simple(data);
	else if (data->strategy == MEDIUM)
		sort_medium(data);
	else if (data->strategy == COMPLEX)
		sort_complex(data);
	else if (data->a.size <= 5)
		sort_simple(data);
	else if (data->a.size <= 50)
		sort_medium(data);
	else
		sort_complex(data);
}

static int	error_msg(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (1);
	ft_memset(&data, 0, sizeof(t_data));
	is_bench(&data, &argc, &argv);
	set_strategy(&data, &argc, &argv);
	if (no_digits(argv) || fill_a(&data.a, argv, --argc)
		|| has_dupes(data.a.top))
		return (error_msg());
	if (is_sorted(&data.a))
		return (free_nodes(data.a.top), 0);
	set_ranks(&data.a);
	dispatch(&data);
	if (data.bench.print)
		print_bench(&data.bench);
	free_nodes(data.a.top);
	free_nodes(data.b.top);
	return (0);
}
