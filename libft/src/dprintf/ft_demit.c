/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_demit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 12:00:00 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/21 12:00:00 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include "ft_dprintf.h"
#include "libft.h"

int	dpf_write(int fd, const char *s, int32_t len)
{
	if (len <= 0)
		return (0);
	return (write(fd, s, len));
}

int	dpf_pad(int fd, char c, int32_t n)
{
	int32_t	i;

	i = 0;
	while (i < n)
	{
		if (write(fd, &c, 1) < 0)
			return (-1);
		i++;
	}
	return (i);
}

int	dpf_emit_str(t_spec *sp, const char *s, int32_t len)
{
	int32_t	pad;

	pad = sp->width - len;
	if (pad < 0)
		pad = 0;
	if ((!sp->minus && dpf_pad(sp->fd, ' ', pad) < 0)
		|| dpf_write(sp->fd, s, len) < 0
		|| (sp->minus && dpf_pad(sp->fd, ' ', pad) < 0))
		return (-1);
	return (pad + len);
}

int	dpf_emit_nbr(t_spec *sp, const char *pre, const char *num, int32_t len)
{
	int32_t	plen;
	int32_t	zeros;
	int32_t	pad;

	plen = ft_strlen(pre);
	zeros = sp->prec - len;
	if (sp->zero)
		zeros = sp->width - plen - len;
	if (zeros < 0)
		zeros = 0;
	pad = sp->width - plen - zeros - len;
	if (pad < 0)
		pad = 0;
	if ((!sp->minus && dpf_pad(sp->fd, ' ', pad) < 0)
		|| dpf_write(sp->fd, pre, plen) < 0
		|| dpf_pad(sp->fd, '0', zeros) < 0
		|| dpf_write(sp->fd, num, len) < 0
		|| (sp->minus && dpf_pad(sp->fd, ' ', pad) < 0))
		return (-1);
	return (pad + plen + zeros + len);
}
