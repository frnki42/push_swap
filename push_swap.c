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
#include "libft/libft.h"

void	push_swap(int size, char **argv)
{
	if (has_dupes(argv))
		return ;
	ft_printf("size: %i\n", size);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	push_swap(--argc,argv);
}
