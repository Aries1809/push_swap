/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 18:51:17 by kseltenr          #+#    #+#             */
/*   Updated: 2026/11/08 12:00:00 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdint.h>

typedef struct s_node
{
	uint64_t		index;
	int32_t			value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bot;
	int32_t	size;
}	t_stack;

typedef enum e_strat
{
	S_NONE,
	S_SIMPLE,
	S_MEDIUM,
	S_COMPLEX,
	S_ADAPTIVE
}	t_strat;

// pls dont mess with the order cause its important bru
typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_op;

typedef struct s_ps
{
	t_stack	a;
	t_stack	b;
	t_strat	strategy;
	int8_t	bench;
	double	disorder;
	int64_t	counts[OP_COUNT];
}	t_ps;

/* PARSING.C */
void	ps_parse(int32_t ac, char **av, t_ps *ps);

/* STACK.C */
int32_t	stack_add(t_stack *stack, int32_t value, uint64_t index);
int32_t	stack_has_value(t_stack *stack, int32_t value);
void	stack_free(t_stack *stack);

/* DISORDER.C */
double	ps_disorder(t_stack *stack);

/* OPS.C */
void	ps_op(t_ps *ps, t_op op);
void	ps_op_n(t_ps *ps, t_op op, int64_t n);

/* OP1.C */
void	sa(t_stack *stack);

#endif
