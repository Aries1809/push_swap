/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 18:51:17 by kseltenr          #+#    #+#             */
/*   Updated: 2026/11/07 22:11:56 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdint.h>

typedef struct s_ps
{
	int8_t	bench;
	int8_t	flags;
}			t_ps;

typedef struct s_stack
{
	uint64_t			index;
	int32_t				value;
	struct s_stack		*prev;
	struct s_stack		*next;
}						t_stack;

#endif
