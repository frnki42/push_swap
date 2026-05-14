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

int	error_msg()
{
	return (write(2, "Error\n", 6));
}

void	push_swap(t_stack *a, t_stack *b)
{
	(void)b;
	ft_printf("size: %i\n", a->size);
	while (a->size--)
		ft_printf("a->nbr[%i] = %i\n", a->size, a->nbr[a->size]);
}
/*
void	set_nbr(t_stack *stack, char **argv)
{
	int	i;

	i = -1;
	while (++i < stack->size)
		stack->nbr[i] = ft_atoi(argv[i]);
}
*/
int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2 || no_digits(++argv) || init_stacks(&a, &b, --argc))
		return (error_msg());
	//	set_nbr(&a, argv);
	push_swap(&a,&b);
	free(a.nbr);
	free(b.nbr);
}
