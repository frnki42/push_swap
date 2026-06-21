#include "push_swap.h"

/*
scans b once, tracks the index of the largest value. Returns position from top
*/
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

/*
computes both directions: fwd = pos rotations forward, bck = size - pos backward.
Takes whichever is smaller. The while (0 < fwd--) pattern executes exactly fwd times and is a no-op when pos == 0
*/

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
/*
push everything to b, then loop: find max position, rotate it to top, pa. 
Each pa places the current largest on top of a, so the result is ascending after all elements return
*/
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
