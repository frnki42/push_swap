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

/*
float	get_disorder(t_stack *a)
{
	int	i;
	int	k;
	int	inv;
	int	pairs;

	if (a->size == 1)
		return (0);
	inv = 0;
	pairs = 0;
	i = -1;
	while (++i < a->size - 1)
	{
		k = i;
		while (++k < a->size && ++pairs)
			if (a->nbr[i] > a->nbr[k])
				inv++;
	}
	printf("disorder: %f\n", disorder);
	return ((float)inv / pairs);
}
*/

int	error_msg()
{
	return (write(2, "Error\n", 6));
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
//	float	disorder;	

	init_stacks(&a, &b);
	if (argc < 2 || no_digits(++argv))
		return (error_msg());
	printf(".frnki\n");
//	disorder = get_disorder(&a);
}
