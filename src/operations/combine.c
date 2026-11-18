/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   combine.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/18 03:30:00 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/18 03:41:23 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_op	op_merge(t_op a, t_op b)
{
	if ((a == OP_RA && b == OP_RB) || (a == OP_RB && b == OP_RA))
		return (OP_RR);
	if ((a == OP_RRA && b == OP_RRB) || (a == OP_RRB && b == OP_RRA))
		return (OP_RRR);
	if ((a == OP_SA && b == OP_SB) || (a == OP_SB && b == OP_SA))
		return (OP_SS);
	return (OP_COUNT);
}

static bool	op_cancels(t_op a, t_op b)
{
	t_op	tmp;

	if (a == b)
		return (a == OP_SA || a == OP_SB || a == OP_SS);
	if (a > b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	return ((a == OP_PA && b == OP_PB) || (a == OP_RA && b == OP_RRA)
		|| (a == OP_RB && b == OP_RRB) || (a == OP_RR && b == OP_RRR));
}

void	ps_op(t_ps *ps, t_op op)
{
	t_op	merged;

	ps_apply(ps, op);
	if (ps->pending == OP_COUNT)
	{
		ps->pending = op;
		return ;
	}
	if (op_cancels(ps->pending, op))
	{
		ps->pending = OP_COUNT;
		return ;
	}
	merged = op_merge(ps->pending, op);
	if (merged != OP_COUNT)
	{
		ps_emit(ps, merged);
		ps->pending = OP_COUNT;
		return ;
	}
	ps_emit(ps, ps->pending);
	ps->pending = op;
}

void	ps_flush(t_ps *ps)
{
	if (ps->pending != OP_COUNT)
		ps_emit(ps, ps->pending);
	ps->pending = OP_COUNT;
}
