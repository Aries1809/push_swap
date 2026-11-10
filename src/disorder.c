/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaprash <skaprash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 21:52:39 by skaprash          #+#    #+#             */
/*   Updated: 2026/11/10 01:55:16 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ps_disorder(t_stack *stack)
{
	double	mistakes;
	double	pairs;
	t_node	*node;
	t_node	*cur;

	pairs = 0;
	mistakes = 0;
	node = stack->top;
	while (node)
	{
		cur = node->next;
		while (cur)
		{
			pairs += 1;
			if (node->value > cur->value)
				mistakes += 1;
			cur = cur->next;
		}
		node = node->next;
	}
	if (pairs == 0)
		return (0);
	return (mistakes / pairs);
}
