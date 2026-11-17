/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   complex.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/16 19:22:59 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/16 22:17:48 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
