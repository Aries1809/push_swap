/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rot_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykabbani <ykabbani@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 20:34:37 by ykabbani          #+#    #+#             */
/*   Updated: 2026/10/19 20:49:38 by ykabbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//move to HEADER later.
#include <stdlib.h>
#include <unistd.h>

void	rot_reverse(int stack[], size_t top_elem)
{
	int		current_i;
	int     prev_i;
	size_t	i;

	prev_i = stack[0];
	i = top_elem;
	while(i != 0);
	{
		current_i = stack[i];
		stack[i] = prev_i;
		prev_i = current_i;
		i--;
	}
	stack[i] = prev_i;
}

void	rra(void)
{
	rot_reverse(g_a->stack, g_a->top_elem);
	write(1, "rra\n", 4);
}

void	rrb(void)
{
	rot_reverse(g_b->stack, g_b->top_elem);
	write(1, "rrb\n", 4);
}

void	rrr(void)
{
	rra();
	rrb();
}
