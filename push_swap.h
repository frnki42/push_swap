
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
	int				rank;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
}	t_stack;

typedef struct s_bench
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
	int	print;
}	t_bench;

typedef struct s_data
{
	t_stack		a;
	t_stack		b;
	t_bench		bench;
	t_strategy	strategy;
	t_strategy	actual;
	double		disorder;
}	t_data;

double	compute_disorder(t_stack *a);
void	print_bench(t_data *data);
int		no_digits(char **argv);
void	free_nodes(t_node *top);
int		fill_a(t_stack *a, char **argv, int size);
int		has_dupes(t_node *top);
void	is_bench(t_data *data, int *argc, char ***argv);
void	set_strategy(t_data *data, int *argc, char ***argv);
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	swap_both(t_data *data);
void	push_a(t_data *data);
void	push_b(t_data *data);
void	rot_a(t_data *data);
void	rot_b(t_data *data);
void	rot_both(t_data *data);
void	rev_rot_a(t_data *data);
void	rev_rot_b(t_data *data);
void	rev_rot_both(t_data *data);
void	sort_simple(t_data *data);
void	sort_medium(t_data *data);
void	set_ranks(t_stack *a);
int		is_sorted(t_stack *a);
void	sort_complex(t_data *data);

#endif
