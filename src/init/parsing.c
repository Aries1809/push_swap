/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parsing.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 04:44:05 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/07 23:07:57 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

void	ps_is_flag(char *str, s_ps *flag)
{
	if (!ft_memcmp(str, "--simple", ft_strlen(str)))
		flag->flags = 1;
	else if (!ft_memcmp(str, "--medium", ft_strlen(str)))
		flag->flags = 2;
	else if (!ft_memcmp(str, "--complex", ft_strlen(str)))
		flag->flags = 3;
	else if (!ft_memcmp(str, "--adaptive", ft_strlen(str)))
		flag->flags = 4;
	else if (!ft_memcmp(str, "--bench", ft_strlen(str)))
		flag->bench = 1;
	else
	{
		ft_dprintf(2, "Error\n");
		exit(1);
	}
	return ;
}

void	stack_init(t_stack *stack)
{
	if (!stack)
		return ;
	stack->index = 0;
	stack->value = 0;
	stack->prev = NULL;
	stack->next = NULL;

	return ;
}

void	stack_add(t_stack *stack, uint64_t *x, int num, t_stack *temp)
{
	stack->index = ++x;
	stack->value = num;
	stack->prev = temp->prev;
	stack->next = NULL;
	temp = stack;
	stack = stack->next;
}

t_stack	ps_parse(int32_t ac, char **av, s_ps *flag)
{
	uint32_t	cnt_av;
	t_stack		stack;
	t_stack		temp;
	uint64_t	x;

	cnt_av = 0;
	x = -1;
	stack_init(&stack);
	stack_init(&temp);
	while (ac > ++cnt_av)
	{
		if (!ft_memcmp(av[cnt_av], "--", 2))
			ps_is_flag(av[cnt_av], flag);
		else if (ft_atoi(av[cnt_av]))
		{
			stack_add(&stack, &x, ft_atoi(av[cnt_av]), &temp);
		}
		else
		{
			ft_dprintf(2, "Error\n");
		}
	}
	return (stack);
}
