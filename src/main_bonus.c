/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main_bonus.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/10 04:55:24 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/10 05:19:50 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int32_t	ck_parse_op(const char *line, t_op *op)
{
	static const char	*names[OP_COUNT] = {"sa\n", "sb\n", "ss\n", "pa\n",
		"pb\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
	int32_t				i;

	i = 0;
	while (i < OP_COUNT)
	{
		if (!ft_strncmp(line, names[i], 5))
		{
			*op = (t_op)i;
			return (1);
		}
		i++;
	}
	return (0);
}

static int32_t	ck_run(t_ps *ps)
{
	char	*line;
	t_op	op;
	int32_t	error;

	error = 0;
	line = get_next_line(0);
	while (line)
	{
		if (!error && ck_parse_op(line, &op))
			ps_apply(ps, op);
		else
			error = 1;
		free(line);
		line = get_next_line(0);
	}
	return (!error);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (0);
	ps_parse(argc, argv, &ps);
	if (!ck_run(&ps))
	{
		stack_free(&ps.a);
		stack_free(&ps.b);
		ft_dprintf(2, "Error\n");
		return (1);
	}
	if (stack_is_sorted(&ps.a) && ps.b.size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stack_free(&ps.a);
	stack_free(&ps.b);
	return (0);
}
