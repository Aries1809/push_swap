/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   chunk.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/17 23:54:55 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/18 01:28:46 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static t_node	*chunk_first(t_ps *ps, t_chunk *chunk)
{
	t_stack	*s;

	s = &ps->b;
	if (chunk->loc == TOP_A || chunk->loc == BOT_A)
		s = &ps->a;
	if (chunk->loc == TOP_A || chunk->loc == TOP_B)
		return (s->top);
	return (s->bot);
}

static t_node	*chunk_next(t_node *node, t_loc loc)
{
	if (loc == TOP_A || loc == TOP_B)
		return (node->next);
	return (node->prev);
}

uint64_t	chunk_min(t_ps *ps, t_chunk chunk)
{
	uint64_t	i;
	uint64_t	ret;
	t_node		*node;

	i = 1;
	node = chunk_first(ps, &chunk);
	ret = node->index;
	while (i < chunk.size)
	{
		node = chunk_next(node, chunk.loc);
		if (node->index < ret)
			ret = node->index;
		i++;
	}
	return (ret);
}
