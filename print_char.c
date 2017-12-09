/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:48:35 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/09 11:11:14 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_char_left_align(unsigned char c, t_struct *f)
{
	f->len += write(1, &c, 1);
	while (f->width > 1)
	{
		f->len += write(1, " ", 1);
		f->width--;
	}
}

static void	ft_print_char_right_align(unsigned char c, t_struct *f)
{
	while (f->width > 1)
	{
		f->len += write(1, " ", 1);
		f->width--;
	}
	f->len += write(1, &c, 1);
}

static void	ft_print_wide_char(wchar_t c, t_struct *f)
{
	(void)c;
	(void)f;
	return ;
}

void		ft_print_char(char type, t_struct *f, va_list ap)
{
	unsigned char	c;
	wchar_t			wc;

	if ((type == 'c' && f->length == L) || type == 'C')
	{
		wc = (wchar_t)va_arg(ap, wint_t);
		ft_print_wide_char(wc, f);
	}
	else if (type == 'c')
	{
		c = (unsigned char)va_arg(ap, int);
		if (f->minus)
			ft_print_char_left_align(c, f);
		else
			ft_print_char_right_align(c, f);
	}
}
