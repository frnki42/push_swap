/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjankovics <bjankovics@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 04:20:42 by bjankovics        #+#    #+#             */
/*   Updated: 2026/06/23 00:00:00 by bjankovics       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	has_dupes(t_node *top)
{
	t_node	*cur;
	t_node	*tmp;

	cur = top;
	while (cur)
	{
		tmp = cur->next;
		while (tmp)
		{
			if (cur->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		cur = cur->next;
	}
	return (0);
}

void	set_strategy(t_data *data, int *argc, char ***argv)
{
	if (!*argv || !**argv)
		return ;
	if (!ft_strncmp(**argv, "--simple", 9))
		data->strategy = SIMPLE;
	else if (!ft_strncmp(**argv, "--medium", 9))
		data->strategy = MEDIUM;
	else if (!ft_strncmp(**argv, "--complex", 10))
		data->strategy = COMPLEX;
	else if (!ft_strncmp(**argv, "--adaptive", 11))
		data->strategy = ADAPTIVE;
	else
		return ;
	(*argv)++;
	(*argc)--;
}

void	is_bench(t_data *data, int *argc, char ***argv)
{
	(*argv)++;
	if (!*argv || !**argv)
		return ;
	if (!ft_strncmp(**argv, "--bench", 7))
	{
		data->bench.print = 1;
		(*argc)--;
		(*argv)++;
	}
}

int	no_digits(char **argv)
{
	char	*str;

	while (*argv)
	{
		str = *argv;
		if (*str == '-' || *str == '+')
			str++;
		if (!*str)
			return (1);
		while (*str)
		{
			if (*str < '0' || *str > '9')
				return (1);
			str++;
		}
		argv++;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	t_node	*cur;

	cur = a->top;
	while (cur && cur->next)
	{
		if (cur->nbr > cur->next->nbr)
			return (0);
		cur = cur->next;
	}
	return (1);
}
