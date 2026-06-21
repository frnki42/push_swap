/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjankovics <bjankovics@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:00:00 by bjankovics        #+#    #+#             */
/*   Updated: 2026/06/21 00:00:00 by bjankovics       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
for each node, counts how many nodes have a smaller nbr.
That count is the node's rank (0 = smallest, n-1 = largest).
Zero push_swap ops — purely preprocessing
*/

static void	medium_set_ranks(t_stack *a)
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

/*
pushes chunks in order:
 	- chunk 0 (ranks 0..cs-1) first
	- chunk √n-1 last
So the highest-rank elements end up at the top of b 
For each chunk, rotates non-matching elements out of the way,
until all chunk members are pushed. O(n√n) ra/pb ops
*/

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

/*
global max-extraction with bidirectional rotation (min(pos, b.size - pos)). 
guarantees the highest-ranked remaining elements are always near the top of b.
Average rotation per pull ≈ √n/2, giving O(n√n) total rb/rrb/pa ops
*/

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
/*
computes cs = ⌈√n⌉ inline, guards size ≤ 1, then runs the three phases.
	- medium_set_ranks: O(n²) preprocessing, no push_swap ops
	- medium_push_all: O(n√n) push_swap ops, pushes chunks in order
	- medium_pull_all: O(n√n) push_swap ops, pulls max-ranked elements
*/

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
	medium_set_ranks(&data->a);
	medium_push_all(data, cs, n);
	medium_pull_all(data);
}
