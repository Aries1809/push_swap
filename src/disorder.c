/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaprash <skaprash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 21:52:39 by skaprash          #+#    #+#             */
/*   Updated: 2026/11/08 12:00:00 by skaprash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Share of all (i < j) pairs where a[i] > a[j]. 0 = sorted, 1 = reversed. */
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
