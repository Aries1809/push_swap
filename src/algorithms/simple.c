/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   simple.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/10 01:20:26 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/10 01:48:43 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* BUBBLE SORT */

static bool	st_is_sorted(t_stack *s)
{
	t_node	*n;

	n = s->top;
	while (n && n->next)
	{
		if (n->value > n->next->value)
			return (false);
		n = n->next;
	}
	return (true);
}

void	s_simple(t_ps *ps)
{
	uint64_t	i;

	while (!st_is_sorted(&ps->a))
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
