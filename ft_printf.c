/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 07:45:42 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/08 13:18:12 by fpetras          ###   ########.fr       */
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

void		ft_print(const char *format, t_struct *f, va_list ap)
{
	if (format[f->i] == 'd' || format[f->i] == 'i' || format[f->i] == 'D')
		ft_print_decimal(format[f->i], f, ap);
	else if (format[f->i] == 'o' || format[f->i] == 'O')
		ft_print_octal(format[f->i], f, ap);
	else if (format[f->i] == 'u' || format[f->i] == 'U')
		ft_print_unsigned_decimal(format[f->i], f, ap);
	else if (format[f->i] == 'x' || format[f->i] == 'X' || format[f->i] == 'p')
		ft_print_hex(format[f->i], f, ap);
	else if (format[f->i] == 'b')
		ft_print_binary(format[f->i], f, ap);
/*	else if (format[f->i] == 'c' || format[f->i] == 'C')
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
