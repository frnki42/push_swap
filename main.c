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

void	set_disorder(t_data *data)
{
	int		inv;
	int		pairs;
	t_node	*cur;
	t_node	*tmp;

	if (data->a.size < 2)
		return ;
	inv = 0;
	pairs = 0;
	cur = data->a.top;
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
	data->disorder = (float)inv / pairs;
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

void	print_info(t_data *data)
{
	t_node	*tmp;
	
	printf("a->size: %i\n", data->a.size);
	printf("a->disorder: %f\n", data->disorder);
	printf("a->top: %p\n", data->a.top);
	printf("b->size: %i\n", data->b.size);
	printf("b->disorder: %f\n", data->disorder);
	printf("b->top: %p\n", data->b.top);
	printf("t_node: %li\n", sizeof(t_node));
	printf("t_stack: %li\n", sizeof(t_stack));
	printf("t_data: %li\n", sizeof(t_data));
	printf("nbrs in stack:\n");
	tmp = data->a.top;
	while (tmp)
	{
		printf("%i\n", tmp->nbr);
		tmp = tmp->next;	
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (1);
	ft_memset(&data, 0, sizeof(t_data));
	if (no_digits(++argv) || fill_a(&data.a, argv, --argc) 
			|| has_dupes(data.a.top))
		return (error_msg());
	set_disorder(&data);
	print_info(&data);
	free_nodes(data.a.top);
}
