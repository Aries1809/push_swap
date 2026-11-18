/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   alg_helpers.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/16 02:55:20 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/17 10:22:30 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_to_top(t_ps *ps, t_stack *s, uint64_t pos)
{
	t_op		r;
	t_op		rr;
	uint64_t	size;

	r = OP_RA;
	rr = OP_RRA;
	size = s->size;
	if (s == &ps->b)
	{
		r = OP_RB;
		rr = OP_RRB;
	}
	if (pos <= size / 2)
		ps_op_n(ps, r, pos);
	else
		ps_op_n(ps, rr, size - pos);
}

uint64_t	pos_of(t_stack *s, uint64_t idx)
{
	t_node		*n;
	uint64_t	i;

	n = s->top;
	i = 0;
	while (n && n->index != idx)
	{
		n = n->next;
		i++;
	}
	return (i);
}

static uint64_t	chunk_walk(t_stack *s, t_loc dir, uint64_t i)
{
	t_node	*node;

	if (dir == TOP_A || dir == TOP_B)
	{
		node = s->top;
		while (i)
		{
			node = node->next;
			i--;
		}
	}
	else
	{
		node = s->bot;
		while (i)
		{
			node = node->prev;
			i--;
		}
	}
	return (node->index);
}

uint64_t	chunk_value(t_ps *ps, t_chunk *chunk, uint64_t i)
{
	if (chunk->loc == TOP_A || chunk->loc == BOT_A)
		return (chunk_walk(&ps->a, chunk->loc, i));
	return (chunk_walk(&ps->b, chunk->loc, i));
}
