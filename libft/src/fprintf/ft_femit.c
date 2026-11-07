/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_femit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 12:00:00 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/21 12:00:00 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include "ft_fprintf.h"
#include "libft.h"

int	fpf_write(FILE *stream, const char *s, int32_t len)
{
	if (len <= 0)
		return (0);
	if (fwrite(s, 1, len, stream) != (size_t)len)
		return (-1);
	return (len);
}

int	fpf_pad(FILE *stream, char c, int32_t n)
{
	int32_t	i;

	i = 0;
	while (i < n)
	{
		if (fputc(c, stream) == EOF)
			return (-1);
		i++;
	}
	return (i);
}

int	fpf_emit_str(t_spec *sp, const char *s, int32_t len)
{
	int32_t	pad;

	pad = sp->width - len;
	if (pad < 0)
		pad = 0;
	if ((!sp->minus && fpf_pad(sp->stream, ' ', pad) < 0)
		|| fpf_write(sp->stream, s, len) < 0
		|| (sp->minus && fpf_pad(sp->stream, ' ', pad) < 0))
		return (-1);
	return (pad + len);
}

int	fpf_emit_nbr(t_spec *sp, const char *pre, const char *num, int32_t len)
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
	if ((!sp->minus && fpf_pad(sp->stream, ' ', pad) < 0)
		|| fpf_write(sp->stream, pre, plen) < 0
		|| fpf_pad(sp->stream, '0', zeros) < 0
		|| fpf_write(sp->stream, num, len) < 0
		|| (sp->minus && fpf_pad(sp->stream, ' ', pad) < 0))
		return (-1);
	return (pad + plen + zeros + len);
}
