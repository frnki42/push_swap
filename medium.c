
#include "push_swap.h"

void	set_ranks(t_stack *a)
{
	t_node	*cur;
	t_node	*cmp;
	int		rank;

	cur = a->top;
	while (cur)
	{
		rank = 0;
		cmp = a->top;
		while (cmp)
		{
			if (cmp->nbr < cur->nbr)
				++rank;
			cmp = cmp->next;
		}
		cur->rank = rank;
		cur = cur->next;
	}
}

static int	medium_find_max(t_stack *b)
{
	t_node	*cur;
	int		max_rank;
	int		max_pos;
	int		ii;

	cur = b->top;
	max_rank = cur->rank;
	max_pos = 0;
	ii = 0;
	while (cur)
	{
		if (cur->rank > max_rank)
		{
			max_rank = cur->rank;
			max_pos = ii;
		}
		++ii;
		cur = cur->next;
	}
	return (max_pos);
}

static void	medium_push_all(t_data *data, int cs, int n)
{
	int	lo;
	int	hi;
	int	pushed;

	lo = 0;
	while (lo < n)
	{
		hi = lo + cs;
		if (hi > n)
			hi = n;
		pushed = 0;
		while (pushed < hi - lo)
		{
			if (data->a.top->rank >= lo && data->a.top->rank < hi)
			{
				push_b(data);
				++pushed;
			}
			else
				rot_a(data);
		}
		lo += cs;
	}
}

static void	medium_pull_all(t_data *data)
{
	int	pos;
	int	fwd;
	int	bck;

	while (data->b.size > 0)
	{
		pos = medium_find_max(&data->b);
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
		push_a(data);
	}
}

void	sort_medium(t_data *data)
{
	int	n;
	int	cs;

	n = data->a.size;
	if (n <= 1)
		return ;
	cs = 1;
	while (cs * cs < n)
		++cs;
	set_ranks(&data->a);
	medium_push_all(data, cs, n);
	medium_pull_all(data);
}
