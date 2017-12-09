/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 08:47:47 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/09 11:24:47 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_string_left_align(char *str, t_struct *f)
{
	int strlen;

	if (!str)
		str = ft_strdup("(null)");
	strlen = ft_strlen(str);
	if (f->precision_specified && strlen > 0)
		strlen = f->precision;
	f->len += write(1, str, strlen);
	while (f->width > strlen)
	{
		f->len += write(1, " ", 1);
		f->width--;
	}
	if (ft_strcmp(str, "(null)") == 0)
		free(str);
}

static void	ft_print_string_right_align(char *str, t_struct *f)
{
	int strlen;

	if (!str)
		str = ft_strdup("(null)");
	strlen = ft_strlen(str);
	if (f->precision_specified && strlen > 0)
		strlen = f->precision;
	while (f->width > strlen)
	{
		f->len += write(1, " ", 1);
		f->width--;
	}
	f->len += write(1, str, strlen);
	if (ft_strcmp(str, "(null)") == 0)
		free(str);
}

static void	ft_print_wide_string(wchar_t *wstr, t_struct *f)
{
	(void)wstr;
	(void)f;
	return ;
}

void		ft_print_string(char type, t_struct *f, va_list ap)
{
	char	*str;
	wchar_t	*wstr;

	if ((type == 's' && f->length == L) || type == 'S')
	{
		wstr = va_arg(ap, wchar_t *);
		ft_print_wide_string(wstr, f);
	}
	else if (type == 's')
	{
		str = va_arg(ap, char *);
		if (f->minus)
			ft_print_string_left_align(str, f);
		else
			ft_print_string_right_align(str, f);
	}
}
