/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 12:00:00 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/21 12:00:00 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <stdint.h>
# include "ft_printf_bonus.h"

int		ft_dprintf(int fd, const char *format, ...);
int		dpf_convert_nbr(t_spec *sp, uint64_t n, int32_t neg);
int		dpf_convert_str(t_spec *sp, const char *s);
int		dpf_emit_nbr(t_spec *sp, const char *pre, const char *num,
			int32_t len);
int		dpf_emit_str(t_spec *sp, const char *s, int32_t len);
int		dpf_pad(int fd, char c, int32_t n);
int		dpf_write(int fd, const char *s, int32_t len);

#endif
