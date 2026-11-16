/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   simple.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/10 01:20:26 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/16 03:04:55 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* BUBBLE SORT */
/*
void	s_simple(t_ps *ps)
{
	uint64_t	i;

	while (!stack_is_sorted(&ps->a))
	{
		i = 0;
		while (++i < ps->a.size)
		{
			if (ps->a.top->index > ps->a.top->next->index)
				ps_op(ps, OP_SA);
			ps_op(ps, OP_RA);
		}
		ps_op(ps, OP_RA);
	}
}
*/

static uint64_t	get_max(uint64_t first, uint64_t second)
{
	if (first > second)
		return (first);
	else
		return (second);
}

static void	sort_three(t_ps *ps)
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

/* INSERTION SORT */
static uint64_t	insert_pos(t_stack *a, uint64_t index)
{
	t_node		*n;
	t_node		*best;
	t_node		*min;

	n = a->top;
	best = NULL;
	min = a->top;
	while (n)
	{
		if (n->index > index && (!best || n->index < best->index))
			best = n;
		if (n->index < min->index)
			min = n;
		n = n->next;
	}
	if (!best)
		best = min;
	n = a->top;
	return (pos_of(a, best->index));
}

static void	bring_to_top(t_ps *ps, uint64_t pos)
{
	if (pos <= ps->a.size / 2)
		ps_op_n(ps, OP_RA, pos);
	else
		ps_op_n(ps, OP_RRA, ps->a.size - pos);
}

void	s_simple(t_ps *ps)
{
	if (stack_is_sorted(&ps->a))
		return ;
	if (ps->a.size == 2)
		return (ps_op(ps, OP_SA));
	while (ps->a.size > 3)
		ps_op(ps, OP_PB);
	sort_three(ps);
	while (ps->b.size > 0)
	{
		bring_to_top(ps, insert_pos(&ps->a, ps->b.top->index));
		ps_op(ps, OP_PA);
	}
	bring_to_top(ps, pos_of(&ps->a, 0));
}
