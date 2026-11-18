/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 18:51:17 by kseltenr          #+#    #+#             */
/*   Updated: 2026/11/18 04:09:39 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef DEBUG
#  define DEBUG 0
# endif

# include "libft.h"
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

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

// also dont mess with the order of this either :gleep:
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

/* For Complex Sort */
typedef enum e_loc
{
	TOP_A,
	BOT_A,
	TOP_B,
	BOT_B
}	t_loc;

typedef struct s_chunk
{
	t_loc		loc;
	uint64_t	size;
}	t_chunk;

typedef struct s_split
{
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
}	t_split;
/* - - - */

typedef struct s_ps
{
	t_stack		a;
	t_stack		b;
	t_strat		strategy;
	char		*applied;
	int8_t		bench;
	double		disorder;
	uint32_t	counts[OP_COUNT];
	t_op		pending;
}	t_ps;

/* PARSING.C */
void		ps_parse(int32_t ac, char **av, t_ps *ps);

/* STACK.C */
int32_t		stack_add(t_stack *stack, int32_t value);
void		stack_free(t_stack *stack);
int32_t		stack_has_value(t_stack *stack, int32_t value);
bool		stack_is_sorted(t_stack *s);
void		stack_normalize(t_stack *s);

/* DISORDER.C */
double		ps_disorder(t_stack *stack);

/* OPS.C */
void		ps_apply(t_ps *ps, t_op op);
void		ps_emit(t_ps *ps, t_op op);
void		ps_op_n(t_ps *ps, t_op op, int64_t n);

/* COMBINE.C */
void		ps_flush(t_ps *ps);
void		ps_op(t_ps *ps, t_op op);

/* OP_HELPERS.C */
t_node		*st_pop_bot(t_stack *s);
t_node		*st_pop_top(t_stack *s);
void		st_push_bot(t_stack *s, t_node *n);
void		st_push_top(t_stack *s, t_node *n);

/* PRIMITIVES.C */
void		st_push(t_stack *from, t_stack *to);
void		st_rotate(t_stack *s);
void		st_rrotate(t_stack *s);
void		st_swap(t_stack *s);

/* GENERAL_HELPERS */
void		bring_to_top(t_ps *ps, t_stack *s, uint64_t pos);
void		move_from_to(t_ps *ps, t_loc from, t_loc to);
uint64_t	pos_of(t_stack *s, uint64_t idx);
uint64_t	cost_to_top(t_stack *s, uint64_t pos);
void		sort_three(t_ps *ps);

/* SIMPLE.C */
void		s_simple(t_ps *ps);

/* COMPLEX_HELPERS */
void		base_case(t_ps *ps, t_chunk *chunk);
uint64_t	chunk_min(t_ps *ps, t_chunk chunk);
uint64_t	chunk_value(t_ps *ps, t_chunk *chunk, uint64_t i);
void		sort_chunk_three(t_ps *ps, t_chunk *chunk);

/* MEDIUM.C */
void		s_medium(t_ps *ps);

/* COMPLEX.C */
void		s_complex(t_ps *ps);

/* ADAPTIVE.C */
void		s_adaptive(t_ps *ps);

/* BENCH.C */
void		bench(t_ps *ps);

#endif
