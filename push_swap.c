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

void	push_swap(int size, char **argv)
{
	(void)argv;
	ft_printf("size: %i\n", size);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2 || no_digits(++argv) || init_stacks(&a, &b, --argc))
		return (error_msg());
	push_swap(argc, argv);
	free(a.nbr);
	free(b.nbr);
}
