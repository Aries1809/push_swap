/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 18:51:17 by kseltenr          #+#    #+#             */
/*   Updated: 2026/11/09 19:33:27 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>


// index is just the argument position rn which is kinda useless
// we might want to change it to the sorted index
// but we'd need to do stuff for that
// (it would be useful for radix or chunk sorting)
typedef struct s_node
{
	uint64_t		index;
	int32_t			value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node		*top;
	t_node		*bot;
	uint64_t	size;
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
	uint32_t	counts[OP_COUNT];
}	t_ps;

/* PARSING.C */
void	ps_parse(int32_t ac, char **av, t_ps *ps);

/* STACK.C */
int32_t	stack_add(t_stack *stack, int32_t value, uint64_t index);
void	stack_free(t_stack *stack);
int32_t	stack_has_value(t_stack *stack, int32_t value);

/* DISORDER.C */
double	ps_disorder(t_stack *stack);

/* OPS.C */
void	ps_op(t_ps *ps, t_op op);
void	ps_op_n(t_ps *ps, t_op op, int64_t n);

/* OP_HELPERS.C */
t_node	*st_pop_bot(t_stack *s);
t_node	*st_pop_top(t_stack *s);
void	st_push_bot(t_stack *s, t_node *n);
void	st_push_top(t_stack *s, t_node *n);

/* PRIMITIVES.C */
void	st_push(t_stack *from, t_stack *to);
void	st_rotate(t_stack *s);
void	st_rrotate(t_stack *s);
void	st_swap(t_stack *s);

/* SIMPLE.C */
void	s_simple(t_ps *ps);

/* BENCH.C */
void	bench(t_ps *ps);

#endif
