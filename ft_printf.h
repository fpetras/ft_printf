/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 07:42:38 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/07 08:49:09 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define H	1
# define HH 2
# define L	3
# define LL	4
# define J	5
# define Z	6

typedef struct	s_struct
{
	int			i;
	int			len;

	int			hash;
	int			zero;
	int			minus;
	int			plus;
	int			space;

	int			width;
	int			precision_specified;
	int			precision;
	int			length;
}				t_struct;

int				ft_printf(const char *format, ...);
void			ft_process_modifiers(const char *format, t_struct *f);
void			ft_flags(const char *format, t_struct *f);
void			ft_width(const char *format, t_struct *f);
void			ft_precision(const char *format, t_struct *f);
void			ft_length(const char *format, t_struct *f);

int				ft_putchar_pf(char c);
int				ft_putstr_pf(const char *s);
int				ft_strchr_pf(const char *s, int c);
int				ft_itoa_base_pf(intmax_t value, int base);
int				ft_nbr_len(intmax_t value, int base);

#endif
