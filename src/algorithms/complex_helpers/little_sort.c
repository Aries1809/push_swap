/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   little_sort.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/18 01:15:48 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/18 01:16:28 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	base_case(t_ps *ps, t_chunk *chunk)
{
	t_stack		*s;
	uint64_t	cnt;

	s = &ps->a;
	cnt = chunk->size;
	while (cnt--)
		move_from_to(ps, chunk->loc, TOP_A);
	if (chunk->size == 2 && s->top->index > s->top->next->index)
		ps_op(ps, OP_SA);
}

void	sort_chunk_three(t_ps *ps, t_chunk *chunk)
{
	uint64_t	cnt;

	cnt = chunk->size;
	while (cnt--)
		move_from_to(ps, chunk->loc, TOP_A);
	if (ps->a.size == 3)
		return (sort_three(ps));
	if (ps->a.top->index > ps->a.top->next->index
		&& ps->a.top->index > ps->a.top->next->next->index)
		ps_op(ps, OP_SA);
	if (ps->a.top->index < ps->a.top->next->index
		&& ps->a.top->next->index > ps->a.top->next->next->index)
	{
		ps_op(ps, OP_RA);
		ps_op(ps, OP_SA);
		ps_op(ps, OP_RRA);
	}
	if (ps->a.top->index > ps->a.top->next->index)
		ps_op(ps, OP_SA);
}
