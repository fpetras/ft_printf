/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 07:45:42 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/06 19:17:02 by fpetras          ###   ########.fr       */
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

void		ft_print_dec(char type, t_struct *f, va_list ap)
{
	if (type == 'd' || type == 'i')
	{
		if (!f->length)
			printf("%d", va_arg(ap, int));
		else if (f->length == HH)
			printf("%hhd", va_arg(ap, signed char));
		else if (f->length == H)
			printf("%hd", va_arg(ap, short));
		else if (f->length == L)
			printf("%ld", va_arg(ap, long));
		else if (f->length == LL)
			printf("%lld", va_arg(ap, long long));
		else if (f->length == J)
			printf("%jd", va_arg(ap, intmax_t));
		else if (f->length == Z)
			printf("%zd", va_arg(ap, size_t));
	}
	else if (type == 'D')
		printf("%D", va_arg(ap, long));
}

void		ft_print(const char *format, t_struct *f, va_list ap)
{
	if (format[f->i] == 'd' || format[f->i] == 'i' || format[f->i] == 'D')
		ft_print_dec(format[f->i], f, ap);
	else if (format[f->i] == 'o' || format[f->i] == 'O')
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
		f->len += write(1, "%", 1);
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
