/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   simple.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/10 01:20:26 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/15 14:54:12 by kseltenr        ###   ########.fr        */
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
			if (ps->a.top->value > ps->a.top->next->value)
				ps_op(ps, OP_SA);
			ps_op(ps, OP_RA);
		}
		ps_op(ps, OP_RA);
	}
}
*/

static int32_t	get_max(int32_t first, int32_t second)
{
	if (first > second)
		return (first);
	else
		return (second);
}

static void	sort_three(t_ps *ps)
{
	t_node	*t;
	int32_t	max;

	t = ps->a.top;
	max = get_max(t->value, get_max(t->next->value, t->next->next->value));
	if (t->value == max)
		ps_op(ps, OP_RA);
	else if (t->next->value == max)
		ps_op(ps, OP_RRA);
	if (ps->a.top->value > ps->a.top->next->value)
		ps_op(ps, OP_SA);
}

/* INSERTION SORT */
static uint64_t	insert_pos(t_stack *a, int32_t value)
{
	t_node		*n;
	t_node		*best;
	t_node		*min;
	uint64_t	i;

	n = a->top;
	best = NULL;
	min = a->top;
	while (n)
	{
		if (n->value > value && (!best || n->value < best->value))
			best = n;
		if (n->value < min->value)
			min = n;
		n = n->next;
	}
	if (!best)
		best = min;
	i = 0;
	n = a->top;
	while (n != best && i++ < INT32_MAX)
		n = n->next;
	return (i);
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
	while (ps->a.size > 3)
		ps_op(ps, OP_PB);
	sort_three(ps);
	while (ps->b.size > 0)
	{
		bring_to_top(ps, insert_pos(&ps->a, ps->b.top->value));
		ps_op(ps, OP_PA);
	}
	bring_to_top(ps, insert_pos(&ps->a, INT32_MIN));
}
