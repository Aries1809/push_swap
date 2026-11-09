/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   primitives.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/09 05:06:28 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/09 05:27:23 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	st_swap(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (s->size < 2)
		return ;
	first = st_pop_top(s);
	second = st_pop_top(s);
	st_push_top(s, first);
	st_push_top(s, second);
}

void	st_push(t_stack *from, t_stack *to)
{
	if (!from->size)
		return ;
	st_push_top(to, st_pop_top(from));
}

void	st_rotate(t_stack *s)
{
	if (s->size < 2)
		return ;
	st_push_bot(s, st_pop_top(s));
}

void	st_rrotate(t_stack *s)
{
	if (s->size < 2)
		return ;
	st_push_top(s, st_pop_bot(s));
}
