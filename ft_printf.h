/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 07:42:38 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/10 14:46:57 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <wchar.h>

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

	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			hash;

	int			width;
	int			precision_specified;
	int			precision;
	int			length;
}				t_struct;

int				ft_printf(const char *format, ...);
void			ft_parse_modifiers(const char *format, t_struct *f, va_list ap);
void			ft_print_decimal(char type, t_struct *f, va_list ap);
void			ft_print_unsigned_decimal(char type, t_struct *f, va_list ap);
void			ft_print_octal(char type, t_struct *f, va_list ap);
void			ft_print_hex(char type, t_struct *f, va_list ap);
void			ft_print_pointer(char type, t_struct *f, va_list ap);
void			ft_print_binary(char type, t_struct *f, va_list ap);
void			ft_print_char(char type, t_struct *f, va_list ap);
void			ft_print_string(char type, t_struct *f, va_list ap);
void			ft_print_percent_sign(char type, t_struct *f);

int				ft_itoa_base_pf(intmax_t value, int base);
int				ft_uitoa_base_pf(uintmax_t value, int base, char letter);
int				ft_signed_nbr_len(intmax_t value, int base);
int				ft_unsigned_nbr_len(uintmax_t value, int base);
void			ft_putwchar_pf(wchar_t wc, t_struct *f);
void			ft_putwstr_pf(wchar_t *wstr, t_struct *f);

#endif
