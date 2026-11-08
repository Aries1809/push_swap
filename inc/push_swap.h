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

typedef enum e_strat
{
	S_NONE,
	S_SIMPLE,
	S_MEDIUM,
	S_COMPLEX,
	S_ADAPTIVE,
}	t_strat;

typedef struct s_ps
{
	int8_t	bench;
	t_strat	strategy;
}			t_ps;

typedef struct s_stack
{
	uint64_t		index;
	int32_t			value;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

/* PARSING.C */
t_stack	*ps_parse(int32_t ac, char **av, t_ps *flag);

/* STACK.C */
int32_t	stack_add(t_stack **head, t_stack **tail, int32_t value,
			uint64_t index);
int32_t	stack_has_value(t_stack *stack, int32_t value);
void	stack_free(t_stack **stack);

/* DISORDER.C */
double	ps_disorder(t_stack *stack);

/* OP1.C */
void	sa(t_stack *stack);

#endif
