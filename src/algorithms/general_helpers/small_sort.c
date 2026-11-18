/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   small_sort.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/17 23:16:47 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/17 23:17:04 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static uint64_t	get_max(uint64_t first, uint64_t second)
{
	if (first > second)
		return (first);
	else
		return (second);
}

void	sort_three(t_ps *ps)
{
	t_node		*t;
	uint64_t	max;

	t = ps->a.top;
	max = get_max(t->index, get_max(t->next->index, t->next->next->index));
	if (t->index == max)
		ps_op(ps, OP_RA);
	else if (t->next->index == max)
		ps_op(ps, OP_RRA);
	if (ps->a.top->index > ps->a.top->next->index)
		ps_op(ps, OP_SA);
}
