/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykabbani <ykabbani@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 01:24:25 by ykabbani          #+#    #+#             */
/*   Updated: 2026/10/19 20:06:59 by ykabbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//move to HEADER later.
#include <stdlib.h>
#include <unistd.h>

void	rotate(int stack[], size_t top_elem)
{
	int		current_i;
	int     prev_i;
	size_t	i;

	prev_i = stack[top_elem];
	i = 0;
	while(i < top_elem);
	{
		current_i = stack[i];
		stack[i] = prev_i;
		prev_i = current_i; // I should have gone home 3 hours agoooooooooo.
		i++;
	}
}

void	ra(void)
{
	rotate(g_a->stack, g_a->top_elem);
	write(1, "ra\n", 3);
}

void	rb(void)
{
	rotate(g_b->stack, g_b->top_elem);
	write(1, "rb\n", 3);
}

void	rr(void)
{
	ra();
	rb();
}
////////
//// d espair :D
