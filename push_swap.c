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
void	free_stuff(t_stack *a, t_stack *b)
{
	if (a->nbr)
		free(a->nbr);
	if (b->nbr)
		free(b->nbr);
}
int	error_msg(t_stack *a, t_stack *b)
{
	free_stuff(a, b);
	return (write(2, "Error\n", 6));
}

int	set_nbr(t_stack *a, char **argv)
{
	int		i;
	int		k;
	int		sign;
	long	nbr;

	i = -1;
	while (++i < a->size)
	{
		sign = 1;
		nbr = 0;
		k = 0;
		if (argv[i][k] == '-' || argv[i][k] == '+')
			if (argv[i][k++] == '-')
				sign = -sign;
		k--;
		while (argv[i][++k] >= '0' && argv[i][k] <= '9')
			nbr = nbr * 10 + argv[i][k] - '0';
		if (nbr != (int)nbr)
			return (1);
		a->nbr[i] = nbr * sign;
	}
	return (0);
}

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
	return ((float)inv / pairs);
}

void	push_swap(t_stack *a, t_stack *b)
{
	(void)b;
	ft_printf("size: %i\n", a->size);
	while (a->size--)
		ft_printf("a->nbr[%i] = %i\n", a->size, a->nbr[a->size]);
}
#include <stdio.h>				//remove me!!!
int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	float	disorder;	

	if (argc < 2 || no_digits(++argv) || init_stacks(&a, &b, --argc)
			|| set_nbr(&a, argv) || has_dupes(&a))
		return (error_msg(&a, &b));
	disorder = get_disorder(&a);
	printf("disorder: %f\n", disorder);
	push_swap(&a,&b);
	free(a.nbr);
	free(b.nbr);
}
