
#include "push_swap.h"

static int	simple_find_max(t_stack *b)
{
	t_node	*cur;
	int		max;
	int		max_pos;
	int		ii;

	cur = b->top;
	max = cur->nbr;
	max_pos = 0;
	ii = 0;
	while (cur)
	{
		if (cur->nbr > max)
		{
			max = cur->nbr;
			max_pos = ii;
		}
		++ii;
		cur = cur->next;
	}
	return (max_pos);
}

static void	simple_bring_max(t_data *data, int pos)
{
	int	fwd;
	int	bck;

	fwd = pos;
	bck = data->b.size - pos;
	if (fwd <= bck)
	{
		while (0 < fwd--)
			rot_b(data);
	}
	else
	{
		while (0 < bck--)
			rev_rot_b(data);
	}
}

void	sort_simple(t_data *data)
{
	int	pos;

	if (data->a.size <= 1)
		return ;
	while (data->a.size > 0)
		push_b(data);
	while (data->b.size > 0)
	{
		pos = simple_find_max(&data->b);
		simple_bring_max(data, pos);
		push_a(data);
	}
}
