/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   alg_helpers.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/16 02:55:20 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/16 02:57:14 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

uint64_t	pos_of(t_stack *s, uint64_t idx)
{
	t_node		*n;
	uint64_t	i;

	n = s->top;
	i = 0;
	while (n && n->index != idx)
	{
		n = n->next;
		i++;
	}
	return (i);
}
