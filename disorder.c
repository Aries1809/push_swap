/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   disorder.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/11 18:54:05 by kseltenr         #+#    #+#              */
/*   Updated: 2026/10/11 19:27:25 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

float	calc_disorder(char **stack)
{
	float	mistakes;
	int		pairs;
	int		cnt;

	mistakes = 0;
	pairs = 0;
	cnt = 0;
	while (stack[cnt + 1])
	{
		if (ft_atoi(stack[cnt]) > ft_atoi(stack[cnt + 1]))
			pairs += 1;
		else
			mistakes += 1;
		cnt++;
		return(mistakes / pairs);
	}
