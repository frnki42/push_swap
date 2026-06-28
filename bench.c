
#include "push_swap.h"

static void	bench_kv(char *key, int val)
{
	ft_putstr_fd(key, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(val, 2);
	ft_putchar_fd(' ', 2);
}

static void	print_strategy(t_strategy s)
{
	if (s == SIMPLE)
		ft_putstr_fd("Simple", 2);
	else if (s == MEDIUM)
		ft_putstr_fd("Medium", 2);
	else if (s == COMPLEX)
		ft_putstr_fd("Complex", 2);
	else
		ft_putstr_fd("Adaptive", 2);
}

static void	print_complexity(t_strategy actual)
{
	if (actual == SIMPLE)
		ft_putstr_fd("O(n^2)", 2);
	else if (actual == MEDIUM)
		ft_putstr_fd("O(n*sqrt(n))", 2);
	else
		ft_putstr_fd("O(n log n)", 2);
}

static void	print_oplines(t_bench *b)
{
	ft_putstr_fd("[bench] ", 2);
	bench_kv("sa", b->sa);
	bench_kv("sb", b->sb);
	bench_kv("ss", b->ss);
	bench_kv("pa", b->pa);
	bench_kv("pb", b->pb);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ", 2);
	bench_kv("ra", b->ra);
	bench_kv("rb", b->rb);
	bench_kv("rr", b->rr);
	bench_kv("rra", b->rra);
	bench_kv("rrb", b->rrb);
	bench_kv("rrr", b->rrr);
	ft_putchar_fd('\n', 2);
}

void	print_bench(t_data *data)
{
	t_bench	*b;
	int		pct;

	b = &data->bench;
	pct = (int)(data->disorder * 10000 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(pct / 100, 2);
	ft_putchar_fd('.', 2);
	if (pct % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(pct % 100, 2);
	ft_putstr_fd("%\n[bench] strategy: ", 2);
	print_strategy(data->strategy);
	ft_putstr_fd(" / ", 2);
	print_complexity(data->actual);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(b->sa + b->sb + b->ss + b->pa + b->pb + b->ra
		+ b->rb + b->rr + b->rra + b->rrb + b->rrr, 2);
	ft_putchar_fd('\n', 2);
	print_oplines(b);
}
