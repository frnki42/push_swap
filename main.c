
#include "push_swap.h"

static void	dispatch(t_data *data)
{
	if (data->strategy == ADAPTIVE)
	{
		if (data->disorder < 0.2)
			data->actual = SIMPLE;
		else if (data->disorder < 0.5)
			data->actual = MEDIUM;
		else
			data->actual = COMPLEX;
	}
	else
		data->actual = data->strategy;
	if (data->actual == SIMPLE)
		sort_simple(data);
	else if (data->actual == MEDIUM)
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
	data.disorder = compute_disorder(&data.a);
	dispatch(&data);
	if (data.bench.print)
		print_bench(&data);
	free_nodes(data.a.top);
	free_nodes(data.b.top);
	return (0);
}
