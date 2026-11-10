/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bench.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/10 02:51:32 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/10 04:27:23 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include "push_swap.h"

static void	b_print_ops(uint32_t *counts)
{
	const char	*names;
	int32_t		i;
	uint8_t		len;

	names = "sa sb ss pa pb ra rb rr rrarrbrrr";
	i = 0;
	len = 2;
	ft_dprintf(2, "[bench] ");
	while (i < OP_COUNT)
	{
		if (i == OP_RA)
			ft_dprintf(2, "\n[bench] ");
		if (i >= OP_RRA)
			len = 3;
		write(2, names + i * 3, len);
		ft_dprintf(2, ":\t%u\t", counts[i++]);
	}
	ft_dprintf(2, "\n");
}

static void	b_print_total(uint32_t *counts)
{
	uint32_t	total;
	int32_t		i;

	total = 0;
	i = 0;
	while (i < OP_COUNT)
		total += counts[i++];
	ft_dprintf(2, "[bench] total_ops:\t%u\n", total);
}

static void	b_print_strat(t_strat s)
{
	const char	*names[] = {"None", "Simple / O(n²)", "Medium / O(n√n)",
		"Complex / O(n log n)", "Adaptive / O(n√n)"};

	ft_dprintf(2, "[bench] strategy:\t%s\n", names[s]);
}

static void	b_print_disorder(double fl)
{
	int32_t	num;

	num = (int32_t)(fl * 10000 + 0.5);
	ft_dprintf(2, "[bench] disorder:\t%d.%02d%%\n", num / 100, num % 100);
}

void	bench(t_ps *ps)
{
	b_print_disorder(ps->disorder);
	b_print_strat(ps->strategy);
	b_print_total(ps->counts);
	b_print_ops(ps->counts);
}
