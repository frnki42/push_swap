/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki <frnki@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 04:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2026/04/20 16:20:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	has_dupes(char **argv)
{

}

static int	exceeds_int(char **argv)
{

}

static int	no_digits(char **argv)
{

}

int	invalid_input(char **argv)
{
	if (no_digits(argv) || exceeds_int(argv) || has_dupes(argv))
		return (1);

