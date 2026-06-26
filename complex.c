
#include "push_swap.h"

static void	complex_pass(t_data *data, int bit)
{
	int	n;
	int	ii;

	n = data->a.size;
	ii = -1;
	while (++ii < n)
	{
		if (data->a.top->rank & (1 << bit))
			rot_a(data);
		else
			push_b(data);
	}
	while (data->b.size > 0)
		push_a(data);
}

void	sort_complex(t_data *data)
{
	int	n;
	int	bits;
	int	ii;

	n = data->a.size;
	if (n <= 1)
		return ;
	bits = 0;
	while ((1u << bits) < (unsigned int)n)
		++bits;
	set_ranks(&data->a);
	ii = -1;
	while (++ii < bits)
		complex_pass(data, ii);
}
