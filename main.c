/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki <frnki@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 04:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2026/04/20 16:20:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>				//remove me!!!

void	set_disorder(t_stack *a)
{
	int		inv;
	int		pairs;
	t_node	*cur;
	t_node	*tmp;

	if (a->size < 2)
		return ;
	inv = 0;
	pairs = 0;
	cur = a->top;
	while (cur)
	{
		tmp = cur->next;
		while (tmp)
		{
			if (cur->nbr > tmp->nbr)
				inv++;
			pairs++;
			tmp = tmp->next;
		}
		cur = cur->next;
	}
	a->disorder = (float)inv / pairs;
}

void	free_nodes(t_node *top)
{
	t_node	*tmp;

	while (top)
	{
		tmp = top;
		top = top->next;
		free(tmp);		
	}
}

int	error_msg()
{
	return (write(2, "Error\n", 6));
}

void	print_info(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	
	printf("a->size: %i\n", a->size);
	printf("a->disorder: %f\n", a->disorder);
	printf("a->top: %p\n", a->top);
	printf("b->size: %i\n", b->size);
	printf("b->disorder: %f\n", b->disorder);
	printf("b->top: %p\n", b->top);
	printf("t_node: %li\n", sizeof(t_node));
	printf("t_stack: %li\n", sizeof(t_stack));
	printf("nbrs in stack:\n");
	tmp = a->top;
	while (tmp)
	{
		printf("%i\n", tmp->nbr);
		tmp = tmp->next;	
	}
	printf("disorder: %f\n", a->disorder);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (1);
	init_stacks(&a, &b);
	if (no_digits(++argv) || fill_a(&a, argv, --argc) || has_dupes(a.top))
		return (error_msg());
	set_disorder(&a);
	print_info(&a, &b);
	free_nodes(a.top);
}
