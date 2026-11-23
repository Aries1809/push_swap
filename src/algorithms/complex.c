/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   complex.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/16 19:22:59 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/18 06:37:26 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 3-way Quicksort*/
static void	set_split_locs(t_loc loc, t_split *dest)
{
	dest->max.size = 0;
	dest->mid.size = 0;
	dest->min.size = 0;
	if (loc == TOP_A)
		dest->max.loc = BOT_A;
	else
		dest->max.loc = TOP_A;
	if (loc == TOP_A || loc == BOT_A)
		dest->mid.loc = TOP_B;
	else
		dest->mid.loc = BOT_A;
	if (loc == BOT_B)
		dest->min.loc = TOP_B;
	else
		dest->min.loc = BOT_B;
}

static void	route(t_ps *ps, t_loc from, t_chunk *to)
{
	move_from_to(ps, from, to->loc);
	to->size++;
}

static void	split_chunks(t_ps *ps, t_chunk chunk, t_split *dest)
{
	uint64_t	lo;
	uint64_t	p1;
	uint64_t	p2;
	uint64_t	r;

	lo = chunk_min(ps, chunk);
	p1 = lo + chunk.size / 3;
	p2 = lo + chunk.size * 2 / 3;
	while (chunk.loc != TOP_A && chunk.size
		&& chunk_value(ps, &chunk, 0) == (lo + chunk.size - 1))
	{
		move_from_to(ps, chunk.loc, TOP_A);
		chunk.size--;
	}
	while (chunk.size)
	{
		r = chunk_value(ps, &chunk, 0);
		if (r >= p2)
			route(ps, chunk.loc, &dest->max);
		else if (r >= p1)
			route(ps, chunk.loc, &dest->mid);
		else
			route(ps, chunk.loc, &dest->min);
		chunk.size--;
	}
}

static void	sort_chunk(t_ps *ps, t_chunk *chunk)
{
	t_split	dest;

	if (!chunk->size)
		return ;
	if (chunk->loc == BOT_A && chunk->size == ps->a.size)
		chunk->loc = TOP_A;
	if (chunk->loc == BOT_B && chunk->size == ps->b.size)
		chunk->loc = TOP_B;
	if (chunk->size <= 2)
		return (base_case(ps, chunk));
	if (chunk->size == 3)
		return (sort_chunk_three(ps, chunk));
	set_split_locs(chunk->loc, &dest);
	split_chunks(ps, *chunk, &dest);
	sort_chunk(ps, &dest.max);
	sort_chunk(ps, &dest.mid);
	sort_chunk(ps, &dest.min);
}

void	s_complex(t_ps *ps)
{
	t_chunk	chunk;

	ps->applied = "O(n log n)";
	if (stack_is_sorted(&ps->a))
		return ;
	if (ps->a.size == 2)
		return (ps_op(ps, OP_SA));
	if (ps->a.size == 3)
		return (sort_three(ps));
	if (ps->a.size <= 5)
		return (sort_five(ps));
	chunk.loc = TOP_A;
	chunk.size = ps->a.size;
	sort_chunk(ps, &chunk);
}

/* Binary Radix Sort */
/*
void	s_complex(t_ps *ps)
{
	uint64_t	max;
	uint64_t	bits;
	uint64_t	k;
	uint64_t	cnt;

	max = ps->a.size - 1;
	bits = 0;
	while ((max >> bits++) != 0)
		;
	if (stack_is_sorted(&ps->a))
		return ;
	k = -1;
	while (++k < bits)
	{
		cnt = ps->a.size;
		while (cnt--)
		{
			if (((ps->a.top->index >> k) & 1) == 0)
				ps_op(ps, OP_PB);
			else
				ps_op(ps, OP_RA);
		}
		ps_op_n(ps, OP_PA, ps->b.size);
	}
}
*/
