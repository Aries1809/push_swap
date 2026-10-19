/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykabbani <ykabbani@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 00:21:40 by ykabbani          #+#    #+#             */
/*   Updated: 2026/10/19 01:23:44 by ykabbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//move to HEADER later.
#include <stdlib.h>
#include <unistd.h>

//is this similar as array.pop from python?
void	push(int stack_dest[], int stack_src[], size_t *top_d, size_t *top_s)
{
	int	tmp;

	if (top_d == (g_a->total_elements - 1)) // input_check at the very start for empty array.
		return ;								// I think a list with 0 elements isn't an "ERROR".
	stack_dest[top_dest + 1] = stack_src[top_src];
	*top_s += -1; // i++ gave me compilation errors for unused values in get_next_line...
	*top_d += 1; // this looks awful.
}

void	pa(void)
{
	push(g_a->stack, g_b->stack, &(g_a->top_elem), &(g_b->top_elem));
	write(1, "pa\n", 3);
}

void	pb(void)
{
	push(g_b->stack, g_a->stack, &(g_b->top_elem), &(g_a->top_elem));
	write(1, "pa\n", 3);
}
