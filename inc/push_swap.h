/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 18:51:17 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/11 18:51:23 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdint.h>

typedef struct t_ps
{
	int8_t	bench;
	int8_t	flags;
}			s_ps;

typedef struct t_stack
{
	uint64_t			index;
	int64_t				value;
	struct t_stack		*prev;
	struct t_stack		*next;
}						s_stack;

#endif
