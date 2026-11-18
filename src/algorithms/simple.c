/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   simple.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/10 01:20:26 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/18 04:14:34 by kseltenr        ###   ########.fr        */
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

void	s_simple(t_ps *ps)
{
	ps->applied = "O(n²)";
	if (stack_is_sorted(&ps->a))
		return ;
	if (ps->a.size == 2)
		return (ps_op(ps, OP_SA));
	while (ps->a.size > 3)
		ps_op(ps, OP_PB);
	sort_three(ps);
	while (ps->b.size > 0)
	{
		bring_to_top(ps, &ps->a, insert_pos(&ps->a, ps->b.top->index));
		ps_op(ps, OP_PA);
	}
	bring_to_top(ps, &ps->a, pos_of(&ps->a, 0));
}
