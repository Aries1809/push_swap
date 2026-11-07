/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_isorder.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/07 21:52:39 by skaprash         #+#    #+#              */
/*   Updated: 2026/11/07 22:21:17 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_isorder(t_stack *lst)
{
	double	mistakes;
	double	pairs;
	t_stack	*nxt;

	pairs = 0;
	mistakes = 0;
	while (lst->next != NULL)
	{
		nxt = lst->next;
		pairs += 1;
		else if (lst->value > nxt->value)
			mistakes += 1;
		lst = nxt;
	}
	return (mistakes / pairs);
}
