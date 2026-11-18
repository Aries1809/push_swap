/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   adaptive.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/18 04:05:26 by kseltenr         #+#    #+#              */
/*   Updated: 2026/11/18 12:31:55 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_adaptive(t_ps *ps)
{
	if (ps->disorder < 0.2)
		s_simple(ps);
	else if (ps->disorder < 0.5)
		s_medium(ps);
	else
		s_complex(ps);
}
