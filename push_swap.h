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

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

typedef struct s_node
{
	int				nbr;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
}	t_stack;

typedef	struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total_ops;
	int	print;
}	t_bench;

typedef struct s_data
{
	t_stack		a;
	t_stack		b;
	t_bench		bench;
	t_strategy	strategy;
	float		disorder;
}	t_data;

int		no_digits(char **argv);
void	free_nodes(t_node *top);
int		fill_a(t_stack *a, char **argv, int size);
int		has_dupes(t_node *top);
void	is_bench(t_data *data, int *argc, char ***argv);
void	set_strategy(t_data *data, int *argc, char ***argv);
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	swap_both(t_data *data);
void	push_b(t_data *data);

#endif
