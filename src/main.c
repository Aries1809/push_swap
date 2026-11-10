/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 22:01:59 by kseltenr          #+#    #+#             */
/*   Updated: 2026/11/10 02:03:45 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* just for testing, we dont need to display the sorted list */
static void	ps_display(t_ps *ps)
{
	t_node	*node;

	node = ps->a.top;
	while (node)
	{
		ft_printf("%d ", node->value);
		node = node->next;
	}
	ft_printf("\n");
}

static void	ps_dispatch(t_ps *ps)
{
	if (ps->strategy == S_SIMPLE)
		s_simple(ps);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	ps_parse(argc, argv, &ps);
	ps_dispatch(&ps);
	ps_display(&ps);
	stack_free(&ps.a);
	stack_free(&ps.b);
	return (0);
}
