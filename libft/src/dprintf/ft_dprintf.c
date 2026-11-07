/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 12:00:00 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/21 12:00:00 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include "ft_dprintf.h"
#include "libft.h"

static int	dpf_dispatch(t_spec *sp, va_list *ap)
{
	int64_t	n;
	char	c;

	if (sp->conv == 'c')
	{
		c = va_arg(*ap, int);
		return (dpf_emit_str(sp, &c, 1));
	}
	if (sp->conv == 's')
		return (dpf_convert_str(sp, va_arg(*ap, const char *)));
	if (sp->conv == 'p')
		return (dpf_convert_nbr(sp, (uintptr_t)va_arg(*ap, void *), 0));
	if (sp->conv == 'd' || sp->conv == 'i')
	{
		n = va_arg(*ap, int);
		if (n < 0)
			return (dpf_convert_nbr(sp, -n, 1));
		return (dpf_convert_nbr(sp, n, 0));
	}
	if (sp->conv == '%')
		return (dpf_write(sp->fd, "%", 1));
	return (dpf_convert_nbr(sp, va_arg(*ap, unsigned int), 0));
}

static int	dpf_print_chunk(int fd, const char **fmt, va_list *ap)
{
	const char	*start;
	t_spec		sp;

	start = *fmt;
	(*fmt)++;
	if (*start == '%')
	{
		pf_parse(fmt, &sp);
		sp.fd = fd;
		if (!sp.conv)
			return (-1);
		if (ft_strchr(CONVERSIONS, sp.conv))
		{
			(*fmt)++;
			return (dpf_dispatch(&sp, ap));
		}
		*fmt = start + 1;
	}
	while (**fmt && **fmt != '%')
		(*fmt)++;
	return (dpf_write(fd, start, *fmt - start));
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int32_t	count;
	int32_t	ret;

	if (!format || fd < 0)
		return (-1);
	va_start(ap, format);
	count = 0;
	ret = 0;
	while (*format && ret >= 0)
	{
		ret = dpf_print_chunk(fd, &format, &ap);
		count += ret;
	}
	va_end(ap);
	if (ret < 0)
		return (-1);
	return (count);
}
