/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki <frnki@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 04:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2026/04/20 16:20:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				nbr;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
}	t_stack;

int		no_digits(char **argv);
void	init_stacks(t_stack *a, t_stack *b);
#endif
