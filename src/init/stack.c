/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 12:00:00 by kseltenr          #+#    #+#             */
/*   Updated: 2026/11/10 04:58:13 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Append a new node at the bottom of the stack. */
int32_t	stack_add(t_stack *stack, int32_t value, uint64_t index)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->index = index;
	node->value = value;
	node->prev = stack->bot;
	node->next = NULL;
	if (stack->bot)
		stack->bot->next = node;
	else
		stack->top = node;
	stack->bot = node;
	stack->size++;
	return (1);
}

int32_t	stack_has_value(t_stack *stack, int32_t value)
{
	t_node	*cur;

	cur = stack->top;
	while (cur)
	{
		if (cur->value == value)
			return (1);
		cur = cur->next;
	}
	return (0);
}

bool	stack_is_sorted(t_stack *s)
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

void	stack_free(t_stack *stack)
{
	t_node	*next;

	while (stack->top)
	{
		next = stack->top->next;
		free(stack->top);
		stack->top = next;
	}
	stack->bot = NULL;
	stack->size = 0;
}
