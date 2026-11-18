/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   medium.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 03:29:31 by skaprash         #+#    #+#              */
/*   Updated: 2026/11/18 12:44:24 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static uint64_t	ft_highest(t_ps *ps)
{
	uint64_t	res;
	t_node		*tmp;

	tmp = ps->b.top;
	res = tmp->index;
	while (tmp)
	{
		if (res < tmp->index)
			res = tmp->index;
		tmp = tmp->next;
	}
	return (res);
}

static uint64_t	ft_buckets(t_ps *ps)
{
	uint64_t	size;

	size = ps->a.size;
	while (ps->a.size % --size == 0)
		;
	return (size);
}

static void	ft_sortb(t_ps *ps)
{
	uint64_t	highest;

	while (ps->b.size > 0)
	{
		highest = ft_highest(ps);
		if (ps->b.top->index == highest)
			ps_op(ps, OP_PA);
		ps_op(ps, OP_RB);
	}
}

/* BUCKET SORT */
void	s_medium(t_ps *ps)
{
	uint64_t	i;
	uint64_t	j;
	uint64_t	size;
	uint64_t	b_cnt;
	uint64_t	b_size;

	ps->applied = "O(n√n)";
	if (stack_is_sorted(&ps->a))
		return ;
	i = -1;
	size = ps->a.size;
	b_cnt = ft_buckets(ps);
	b_size = size / b_cnt;
	while (++i < b_cnt)
	{
		j = ps->a.size + 1;
		while (--j > 0 && ps->a.size > 0)
		{
			if (ps->a.top->index <= b_size + (i * b_size) || i == b_cnt - 1)
				ps_op(ps, OP_PB);
			else
				ps_op(ps, OP_RA);
		}
	}
	ft_sortb(ps);
}
