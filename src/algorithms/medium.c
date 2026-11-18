/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   medium.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sergk <sergk@student.42.fr>               #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 03:29:31 by sergk            #+#    #+#              */
/*   Updated: 2026/11/19 00:16:14 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static uint64_t	ft_buckets(t_ps *ps)
{
	uint64_t	root;

	root = 1;
	while (ps->a.size / root > root)
		root++;
	if (root * 2 / 5 < 1)
		return (1);
	return (root * 2 / 5);
}

static void	push_bucket(t_ps *ps, uint64_t lo, uint64_t hi)
{
	uint64_t	pushed;
	uint64_t	mid;

	pushed = 0;
	mid = lo + (hi - lo) / 2;
	while (pushed < hi - lo)
	{
		if (ps->a.top->index >= lo && ps->a.top->index < hi)
		{
			ps_op(ps, OP_PB);
			pushed++;
			if (ps->b.top->index < mid && ps->b.size > 1)
				ps_op(ps, OP_RB);
		}
		else
			ps_op(ps, OP_RA);
	}
}

static void	ft_sortb(t_ps *ps)
{
	uint64_t	max;

	while (ps->b.size > 0)
	{
		max = ps->b.size - 1;
		if (ps->b.size >= 2
			&& cost_to_top(&ps->b, pos_of(&ps->b, max - 1))
			< cost_to_top(&ps->b, pos_of(&ps->b, max)))
		{
			bring_to_top(ps, &ps->b, pos_of(&ps->b, max - 1));
			ps_op(ps, OP_PA);
			bring_to_top(ps, &ps->b, pos_of(&ps->b, max));
			ps_op(ps, OP_PA);
			ps_op(ps, OP_SA);
		}
		else
		{
			bring_to_top(ps, &ps->b, pos_of(&ps->b, max));
			ps_op(ps, OP_PA);
		}
	}
}

static bool	ft_weird_input(t_ps *ps)
{
	if (stack_is_sorted(&ps->a))
		return (true);
	if (ps->a.size == 2)
		return (ps_op(ps, OP_SA), true);
	if (ps->a.size == 3)
		return (sort_three(ps), true);
	return (false);
}

void	s_medium(t_ps *ps)
{
	uint64_t	i;
	uint64_t	n;
	uint64_t	count;
	uint64_t	bsize;

	ps->applied = "O(n√n)";
	if (ft_weird_input(ps))
		return ;
	n = ps->a.size;
	count = ft_buckets(ps);
	bsize = n / count;
	i = 0;
	while (i + 1 < count)
	{
		push_bucket(ps, i * bsize, (i + 1) * bsize);
		i++;
	}
	push_bucket(ps, i * bsize, n);
	ft_sortb(ps);
}
