/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 04:44:05 by kseltenr          #+#    #+#             */
/*   Updated: 2026/11/09 04:45:08 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

static void	ps_error(t_ps *ps)
{
	stack_free(&ps->a);
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

/* Parses one number from *str up to a space, tab or '\0' and advances *str. */
static int32_t	ps_atoi(const char **str, int32_t *out)
{
	int64_t		num;
	int32_t		sign;
	const char	*s;

	num = 0;
	sign = 1;
	s = *str;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	if (!ft_isdigit(*s))
		return (0);
	while (*s && *s != ' ' && *s != '\t')
	{
		if (!ft_isdigit(*s))
			return (0);
		num = num * 10 + (*s - '0');
		if (num * sign > INT32_MAX || num * sign < INT32_MIN)
			return (0);
		s++;
	}
	*str = s;
	*out = (int32_t)(num * sign);
	return (1);
}

/* Adds every space/tab-separated number in str to stack a.
 * An argument with no numbers at all ("", "   " or tabs only) is an error. */
static int32_t	ps_add_arg(t_ps *ps, const char *str, uint64_t *index)
{
	int32_t	num;
	int32_t	count;

	count = 0;
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
			str++;
		else if (!ps_atoi(&str, &num) || stack_has_value(&ps->a, num)
			|| !stack_add(&ps->a, num, (*index)++))
			return (0);
		else
			count++;
	}
	return (count > 0);
}

/* Fills ps->a from the arguments and sets the flags. */
void	ps_parse(int32_t ac, char **av, t_ps *ps)
{
	int32_t		i;
	uint64_t	index;

	i = 0;
	index = 0;
	ft_bzero(ps, sizeof(*ps));
	while (++i < ac)
	{
		if (!ft_strncmp(av[i], "--", 2))
		{
			if (!ps_is_flag(av[i], ps))
				ps_error(ps);
		}
		else if (!ps_add_arg(ps, av[i], &index))
			ps_error(ps);
	}
}
