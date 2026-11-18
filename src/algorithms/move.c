/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   move.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/17 09:27:09 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/17 09:44:04 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_to_a(t_ps *ps, t_loc to, t_loc from)
{
	if (to == TOP_A)
	{
		if (from == BOT_A)
			if (ps->a.size > 1)
				ps_op(ps, OP_RRA);
		if (from == BOT_B)
			if (ps->b.size > 1)
				ps_op(ps, OP_RRB);
		if (from == TOP_B || from == BOT_B)
			ps_op(ps, OP_PA);
	}
	if (to == BOT_A)
	{
		if (from == BOT_B)
			ps_op(ps, OP_RRB);
		if (from == TOP_B || from == BOT_B)
			ps_op(ps, OP_PA);
		if (from == TOP_A || from == TOP_B || from == BOT_B)
			if (ps->a.size > 1)
				ps_op(ps, OP_RA);
	}
}

static void	move_to_b(t_ps *ps, t_loc to, t_loc from)
{
	if (to == TOP_B)
	{
		if (from == BOT_A)
			if (ps->a.size > 1)
				ps_op(ps, OP_RRA);
		if (from == TOP_A || from == BOT_A)
			ps_op(ps, OP_PB);
		if (from == BOT_B)
			if (ps->b.size > 1)
				ps_op(ps, OP_RRB);
	}
	if (to == BOT_B)
	{
		if (from == BOT_A)
			ps_op(ps, OP_RRA);
		if (from == TOP_A || from == BOT_A)
			ps_op(ps, OP_PB);
		if (from == TOP_B || from == TOP_A || from == BOT_A)
			if (ps->b.size > 1)
				ps_op(ps, OP_RB);
	}
}

void	move_from_to(t_ps *ps, t_loc from, t_loc to)
{
	if (to == TOP_A || to == BOT_A)
		move_to_a(ps, to, from);
	if (to == TOP_B || to == BOT_B)
		move_to_b(ps, to, from);
}
