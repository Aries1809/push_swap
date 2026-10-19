/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykabbani <ykabbani@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 20:44:41 by ykabbani          #+#    #+#             */
/*   Updated: 2026/10/19 00:18:33 by ykabbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//move to HEADER later.
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int				stack[];
	size_t			top_elem;
	const size_t	total_elements; // necessary for checking empty stack,
}	t_stack;			// might also be useful for some sorting algorithms or the method selector.

void	swap_top2_elements(int stack[], size_t top_elem)
{
	int	tmp;

	if (top_elem == 0) // "top_elem = -1" not possible with size_t,
		return ;		// so for (push stack) we need a check that top_elem != total_elements.
	tmp = stack[top_elem];
	stack[top_elem] = stack[top_elem - 1];
	stack[top_elem - 1] = tmp;
}

void	sa(void)
{
	swap_top2_elements(g_a->stack, g_a->top_elem);
	write(1, "sa\n", 3); // Do we still write if the stack is empty?
}

void    sb(void)
{
	swap_top2_elements(g_b->stack, g_b->top_elem);
	write(1, "sb\n", 3);
}

void	ss(void)
{
	sa();
	sb();
}
