/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 12:00:00 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/21 12:00:00 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H

# include <stdint.h>
# include <stdio.h>
# include "ft_printf_bonus.h"

int		ft_fprintf(FILE *stream, const char *format, ...);
int		fpf_convert_nbr(t_spec *sp, uint64_t n, int32_t neg);
int		fpf_convert_str(t_spec *sp, const char *s);
int		fpf_emit_nbr(t_spec *sp, const char *pre, const char *num,
			int32_t len);
int		fpf_emit_str(t_spec *sp, const char *s, int32_t len);
int		fpf_pad(FILE *stream, char c, int32_t n);
int		fpf_write(FILE *stream, const char *s, int32_t len);

#endif
