/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 07:45:42 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/07 15:21:09 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** %[flags][width][.precision][length]type
*/

#include <stdio.h>

void		test_funct(const char *format, t_struct *f)
{
	printf("current char: %c\n", format[f->i]);
	printf("hash: %d\n", f->hash);
	printf("zero: %d\n", f->zero);
	printf("minus: %d\n", f->minus);
	printf("plus: %d\n", f->plus);
	printf("space: %d\n", f->space);
	printf("width: %d\n", f->width);
	printf("has precision: %d\n", f->precision_specified);
	printf("precision: %d\n", f->precision);
	printf("length: %d\n", f->length);
	printf("f->i: %d\n", f->i);
	printf("remaining string: %s\n", &format[f->i]);
}


void		ft_print_dec_left_align(intmax_t nbr, t_struct *f)
{
	return ;
	int nbrlen;
	int n;

	nbrlen = ft_nbr_len(nbr, 10);
	n = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? -nbr : nbr;
}

void		ft_padding(int nbrlen, t_struct *f)
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

void		ft_print_dec_right_align(intmax_t nbr, t_struct *f)
{
	int nbrlen;
	int n;

	nbrlen = ft_nbr_len(nbr, 10);
	n = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? -nbr : nbr;
	if (f->plus && n == 0 && f->width && !f->precision_specified)
		nbrlen++;
	if (f->space && n == 0)
		f->len += write(1, " ", 1);
	if (f->plus && f->zero && n == 0)
		f->len += write(1, "+", 1);
	if (n == 1 && f->zero)
		f->len += write(1, "-", 1);
	ft_padding(nbrlen, f);
	if (!f->zero && f->plus && n == 0)
		f->len += write(1, "+", 1);
	else if (!f->zero && n == 1)
		f->len += write(1, "-", 1);
	while (++nbrlen <= f->precision)
		f->len += write(1, "0", 1);
	f->len += ft_itoa_base_pf(nbr, 10);
}

void		ft_print_dec2(intmax_t nbr, char type, t_struct *f)
{
	(void)type;
	if (f->minus)
		ft_print_dec_left_align(nbr, f);
	else
		ft_print_dec_right_align(nbr, f);
}

void		ft_print_dec(char type, t_struct *f, va_list ap)
{
	intmax_t nbr;

	if (type == 'd' || type == 'i')
	{
		if (!f->length)
			nbr =  va_arg(ap, int);
		else if (f->length == HH)
			nbr = (signed char)va_arg(ap, int);
		else if (f->length == H)
			nbr = (short)va_arg(ap, int);
		else if (f->length == L)
			nbr = va_arg(ap, long);
		else if (f->length == LL)
			nbr = va_arg(ap, long long);
		else if (f->length == J)
			nbr = va_arg(ap, intmax_t);
		else if (f->length == Z)
			nbr = va_arg(ap, size_t);
	}
	else if (type == 'D')
		nbr = va_arg(ap, long);
	ft_print_dec2(nbr, type, f);
}

void		ft_print(const char *format, t_struct *f, va_list ap)
{
	if (format[f->i] == 'd' || format[f->i] == 'i' || format[f->i] == 'D')
		ft_print_dec(format[f->i], f, ap);
/*	else if (format[f->i] == 'o' || format[f->i] == 'O')
		ft_print_oct(format[f->i], f, ap);
	else if (format[f->i] == 'u' || format[f->i] == 'U')
		ft_print_udec(format[f->i], f, ap);
	else if (format[f->i] == 'x' || format[f->i] == 'X' || format[f->i] == 'p')
		ft_print_hex(format[f->i], f, ap);
	else if (format[f->i] == 'b')
		ft_print_bin(format[f->i], f, ap);
	else if (format[f->i] == 'c' || format[f->i] == 'C')
		ft_print_char(format[f->i], f, ap);
	else if (format[f->i] == 's' || format[f->i] == 'S')
		ft_print_str(format[f->i], f, ap);
	else if (format[f->i] == '%')
		f->len += write(1, "%", 1);*/
}

void		ft_process_string(const char *format, t_struct *f, va_list ap)
{
	while (format[f->i] != '\0')
	{
		if (format[f->i] == '%')
		{
			f->i++;
			if (ft_strchr("#-+ .0123456789hljz", format[f->i]))
				ft_process_modifiers(format, f);
//			test_funct(format, f);
//			exit(0);
			if (ft_strchr("sSpdDioOuUxXcCb%", format[f->i]))
				ft_print(format, f, ap);
		}
		else
			f->len += write(1, &format[f->i], 1);
		f->i++;
	}
}

t_struct	*ft_init_struct(t_struct *f)
{
	f = ft_memalloc(sizeof(t_struct));
	f->i = 0;
	f->len = 0;
	return (f);
}

int			ft_printf(const char *format, ...)
{
	int			len;
	t_struct	*f;
	va_list		ap;

	f = ft_init_struct(f);
	va_start(ap, format);
	if (!ft_strchr(format, '%'))
		f->len += write(1, format, ft_strlen(format));
	else
		ft_process_string(format, f, ap);
	len = f->len;
	free(f);
	va_end(ap);
	return (len);
}
