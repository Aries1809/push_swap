/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ops.c                                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/09 03:41:54 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/10 05:11:50 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_apply(t_ps *ps, t_op op)
{
	if (op == OP_SA || op == OP_SS)
		st_swap(&ps->a);
	if (op == OP_SB || op == OP_SS)
		st_swap(&ps->b);
	if (op == OP_PA)
		st_push(&ps->b, &ps->a);
	if (op == OP_PB)
		st_push(&ps->a, &ps->b);
	if (op == OP_RA || op == OP_RR)
		st_rotate(&ps->a);
	if (op == OP_RB || op == OP_RR)
		st_rotate(&ps->b);
	if (op == OP_RRA || op == OP_RRR)
		st_rrotate(&ps->a);
	if (op == OP_RRB || op == OP_RRR)
		st_rrotate(&ps->b);
}

// this is currently one write per operation
// it should be fine, but it could be better
// we could use buffered output instead
// which would be faster if we have
// lots of operations :leaves:
static void	ps_op_print(t_op op)
{
	const char	*names;
	uint8_t		len;

	names = "sa\n sb\n ss\n pa\n pb\n ra\n rb\n rr\n rra\nrrb\nrrr\n";
	len = 3;
	if (op >= OP_RRA)
		len = 4;
	if (write(1, names + op * 4, len) < 0)
		return ;
}

void	ps_op(t_ps *ps, t_op op)
{
	ps_apply(ps, op);
	ps->counts[op]++;
	ps_op_print(op);
}

// ps_op prints every operations, even if it does nothing
// that is not allowed (i think) so our algorithm
// must never use operations which have no effect
void	ps_op_n(t_ps *ps, t_op op, int64_t n)
{
	while (n-- > 0)
		ps_op(ps, op);
}
