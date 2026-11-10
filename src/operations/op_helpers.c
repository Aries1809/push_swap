/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   op_helpers.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/09 05:11:33 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/10 01:55:13 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*st_pop_top(t_stack *s)
{
	t_node	*n;

	if (!s->size)
		return (NULL);
	n = s->top;
	s->top = n->next;
	if (s->top)
		s->top->prev = NULL;
	else
		s->bot = NULL;
	n->next = NULL;
	s->size--;
	return (n);
}

t_node	*st_pop_bot(t_stack *s)
{
	t_node	*n;

	if (!s->size)
		return (NULL);
	n = s->bot;
	s->bot = n->prev;
	if (s->bot)
		s->bot->next = NULL;
	else
		s->top = NULL;
	n->prev = NULL;
	s->size--;
	return (n);
}

void	st_push_top(t_stack *s, t_node *n)
{
	n->prev = NULL;
	n->next = s->top;
	if (s->top)
		s->top->prev = n;
	else
		s->bot = n;
	s->top = n;
	s->size++;
}

void	st_push_bot(t_stack *s, t_node *n)
{
	n->next = NULL;
	n->prev = s->bot;
	if (s->bot)
		s->bot->next = n;
	else
		s->top = n;
	s->bot = n;
	s->size++;
}
