/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dconvert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 12:00:00 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/21 12:00:00 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_dprintf.h"
#include "libft.h"

static char	*dpf_utoa(t_spec *sp, uint64_t n, char *end)
{
	const char	*digits;
	uint64_t	base;

	digits = "0123456789abcdef";
	if (sp->conv == 'X')
		digits = "0123456789ABCDEF";
	base = 16;
	if (ft_strchr("diu", sp->conv))
		base = 10;
	if (n == 0 && sp->prec != 0)
		*--end = '0';
	while (n)
	{
		*--end = digits[n % base];
		n /= base;
	}
	return (end);
}

static void	dpf_prefix(t_spec *sp, uint64_t n, int32_t neg, char *pre)
{
	*pre = '\0';
	if (neg)
		ft_strlcat(pre, "-", 4);
	else if (sp->plus)
		ft_strlcat(pre, "+", 4);
	else if (sp->space)
		ft_strlcat(pre, " ", 4);
	if (sp->hash && n && sp->conv == 'X')
		ft_strlcat(pre, "0X", 4);
	else if (sp->hash && n)
		ft_strlcat(pre, "0x", 4);
}

int	dpf_convert_nbr(t_spec *sp, uint64_t n, int32_t neg)
{
	char	buf[20];
	char	pre[4];
	char	*num;

	if (sp->conv == 'p' && !n)
		return (dpf_emit_str(sp, "(nil)", 5));
	num = dpf_utoa(sp, n, buf + sizeof(buf));
	dpf_prefix(sp, n, neg, pre);
	return (dpf_emit_nbr(sp, pre, num, buf + sizeof(buf) - num));
}

int	dpf_convert_str(t_spec *sp, const char *s)
{
	int32_t	len;

	if (!s && sp->prec >= 0 && sp->prec < 6)
		s = "";
	else if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (sp->prec >= 0 && sp->prec < len)
		len = sp->prec;
	return (dpf_emit_str(sp, s, len));
}
