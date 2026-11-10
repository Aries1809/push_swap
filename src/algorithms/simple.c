/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   simple.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/10 01:20:26 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/10 04:58:43 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* BUBBLE SORT */
void	s_simple(t_ps *ps)
{
	uint64_t	i;

	while (!stack_is_sorted(&ps->a))
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
