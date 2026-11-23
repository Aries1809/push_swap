/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   small_sort.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/17 23:16:47 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/23 04:57:37 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static uint64_t	get_max(uint64_t first, uint64_t second)
{
	if (first > second)
		return (first);
	else
		return (second);
}

void	sort_three(t_ps *ps)
{
	t_node		*t;
	uint64_t	max;

	t = ps->a.top;
	max = get_max(t->index, get_max(t->next->index, t->next->next->index));
	if (t->index == max)
		ps_op(ps, OP_RA);
	else if (t->next->index == max)
		ps_op(ps, OP_RRA);
	if (ps->a.top->index > ps->a.top->next->index)
		ps_op(ps, OP_SA);
}

static bool	is_rotated_sorted(t_stack *s)
{
	t_node		*n;
	uint64_t	breaks;

	breaks = 0;
	n = s->top;
	while (n->next)
	{
		if (n->index > n->next->index)
			breaks++;
		n = n->next;
	}
	if (s->bot->index > s->top->index)
		breaks++;
	return (breaks <= 1);
}

static uint64_t	cheapest_below(t_stack *a, uint64_t limit)
{
	t_node		*n;
	uint64_t	i;
	uint64_t	best;

	n = a->top;
	i = 0;
	best = a->size;
	while (n)
	{
		if (n->index < limit && (best == a->size
				|| cost_to_top(a, i) < cost_to_top(a, best)))
			best = i;
		n = n->next;
		i++;
	}
	return (best);
}

void	sort_five(t_ps *ps)
{
	uint64_t	limit;

	if (is_rotated_sorted(&ps->a))
		return (bring_to_top(ps, &ps->a, pos_of(&ps->a, 0)));
	limit = ps->a.size - 3;
	while (ps->a.size > 3)
	{
		bring_to_top(ps, &ps->a, cheapest_below(&ps->a, limit));
		ps_op(ps, OP_PB);
	}
	sort_three(ps);
	if (ps->b.size == 2 && ps->b.top->index < ps->b.top->next->index)
		ps_op(ps, OP_SB);
	while (ps->b.size > 0)
		ps_op(ps, OP_PA);
}
