/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 08:06:19 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/08 11:15:40 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_unsigned_decimal_left_align(intmax_t nbr, t_struct *f)
{
	int nbrlen;

	nbrlen = ft_unsigned_nbr_len(nbr, 10);
	while (++nbrlen <= f->precision)
		f->len += write(1, "0", 1);
	f->len += ft_uitoa_base_pf(nbr, 10, 0);
	while (f->width >= nbrlen)
	{
		f->len += write(1, " ", 1);
		f->width--;
	}
}

static void	ft_padding(int nbrlen, t_struct *f)
{
	if (!f->precision_specified)
	{
		while (f->width > nbrlen)
		{
			if (f->zero)
				f->len += write(1, "0", 1);
			else
				f->len += write(1, " ", 1);
			f->width--;
		}
	}
	else
	{
		if (f->plus || f->zero)
			f->width--;
		if (f->precision > nbrlen)
			while (f->width > f->precision)
			{
				if (f->zero)
					f->len += write(1, "0", 1);
				else
					f->len += write(1, " ", 1);
				f->width--;
			}
	}
}

static void	ft_print_unsigned_decimal_right_align(uintmax_t nbr, t_struct *f)
{
	int nbrlen;

	nbrlen = ft_unsigned_nbr_len(nbr, 10);
	ft_padding(nbrlen, f);
	while (++nbrlen <= f->precision)
		f->len += write(1, "0", 1);
	f->len += ft_uitoa_base_pf(nbr, 10, 0);
}

static void	ft_print_unsigned_decimal2(uintmax_t nbr, t_struct *f)
{
	if (f->minus)
		ft_print_unsigned_decimal_left_align(nbr, f);
	else
		ft_print_unsigned_decimal_right_align(nbr, f);
}

void		ft_print_unsigned_decimal(char type, t_struct *f, va_list ap)
{
	uintmax_t nbr;

	if (type == 'u')
	{
		if (!f->length)
			nbr =  va_arg(ap, unsigned int);
		else if (f->length == HH)
			nbr = (unsigned char)va_arg(ap, unsigned int);
		else if (f->length == H)
			nbr = (unsigned short)va_arg(ap, unsigned int);
		else if (f->length == L)
			nbr = va_arg(ap, unsigned long);
		else if (f->length == LL)
			nbr = va_arg(ap, unsigned long long);
		else if (f->length == J)
			nbr = va_arg(ap, uintmax_t);
		else if (f->length == Z)
			nbr = va_arg(ap, size_t);
	}
	else if (type == 'U')
		nbr = va_arg(ap, unsigned long);
	ft_print_unsigned_decimal2(nbr, f);
}
