/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parsing.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 04:44:05 by kseltenr         #+#    #+#              */
/*   Updated: 2026/10/21 16:26:34 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

void	ps_is_flag(char *str, s_ps *flag)
{
	if (!ft_memcmp(str, "--simple", ft_strlen(str)))
		flag->flags = 1;
	else if (!ft_memcmp(str, "--medium", ft_strlen(str)))
		flag->flags = 2;
	else if (!ft_memcmp(str, "--complex", ft_strlen(str)))
		flag->flags = 3;
	else if (!ft_memcmp(str, "--adaptive", ft_strlen(str)))
		flag->flags = 4;
	else if (!ft_memcmp(str, "--bench", ft_strlen(str)))
		flag->bench = 1;
	else
	{
		ft_dprintf(2, "Error: Invalid flag\n");
		exit(1);
	}
	return ;
}

void	ps_parse(int32_t ac, char **av, s_ps *flag)
{
	uint32_t	cnt_av;

	cnt_av = 1;
	while (ac > cnt_av)
	{
		if (!ft_memcmp(av[cnt_av], "--", 2))
		{
			ps_is_flag(av[cnt_av], flag);
			cnt_av++;
		}
	}
}
