/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 22:01:59 by kseltenr          #+#    #+#             */
/*   Updated: 2026/11/08 12:00:00 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	flag;
	t_stack	*stack;

	stack = ps_parse(argc, argv, &flag);
	if (!stack)
		return (0);
	stack_free(&stack);
	return (0);
}
