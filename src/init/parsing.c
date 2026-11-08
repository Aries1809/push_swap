/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 04:44:05 by kseltenr          #+#    #+#             */
/*   Updated: 2026/11/08 21:39:03 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

static void	ps_error(t_stack **stack)
{
	stack_free(stack);
	ft_dprintf(2, "Error\n");
	exit(1);
}

static int32_t	ps_is_flag(const char *str, t_ps *flag)
{
	t_strat	strat;

	if (!ft_strncmp(str, "--bench", 8))
	{
		flag->bench = 1;
		return (1);
	}
	if (!ft_strncmp(str, "--simple", 9))
		strat = S_SIMPLE;
	else if (!ft_strncmp(str, "--medium", 9))
		strat = S_MEDIUM;
	else if (!ft_strncmp(str, "--complex", 10))
		strat = S_COMPLEX;
	else if (!ft_strncmp(str, "--adaptive", 11))
		strat = S_ADAPTIVE;
	else
		return (0);
	if (flag->strategy != S_NONE && flag->strategy != strat)
		return (0);
	flag->strategy = strat;
	return (1);
}

static int32_t	ps_atoi(const char *str, int32_t *out)
{
	int64_t	num;
	int32_t	sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		num = num * 10 + (*str - '0');
		if (num * sign > INT32_MAX || num * sign < INT32_MIN)
			return (0);
		str++;
	}
	*out = (int32_t)(num * sign);
	return (1);
}

static void	init_flag(t_ps *flag)
{
	flag->strategy = S_NONE;
	flag->bench = 0;
}

t_stack	*ps_parse(int32_t ac, char **av, t_ps *flag)
{
	int32_t		i;
	int32_t		num;
	t_stack		*head;
	t_stack		*tail;
	uint64_t	index;

	i = 0;
	index = 0;
	head = NULL;
	tail = NULL;
	init_flag(flag);
	while (++i < ac)
	{
		if (!ft_strncmp(av[i], "--", 2))
		{
			if (!ps_is_flag(av[i], flag))
				ps_error(&head);
		}
		else if (!ps_atoi(av[i], &num) || stack_has_value(head, num)
			|| !stack_add(&head, &tail, num, index++))
			ps_error(&head);
	}
	return (head);
}
