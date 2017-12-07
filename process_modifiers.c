/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_modifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:18:34 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/07 11:14:06 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_length(const char *format, t_struct *f)
{
	if (ft_strchr("hljz", format[f->i]))
	{
		if (format[f->i] == 'h')
		{
			if (format[f->i + 1] == 'h')
				f->length = HH;
			else
				f->length = H;
		}
		else if (format[f->i] == 'l')
		{
			if (format[f->i + 1] == 'l')
				f->length = LL;
			else
				f->length = L;
		}
		else if (format[f->i] == 'j')
			f->length = J;
		else if (format[f->i] == 'z')
			f->length = Z;
		while (ft_strchr("hljz", format[f->i]))
			f->i++;
	}
}

void		ft_precision(const char *format, t_struct *f)
{
	if (format[f->i] == '.')
	{
		f->i++;
		f->precision_specified = 1;
		f->precision = ft_atoi(&format[f->i]);
		while (ft_isdigit(format[f->i]))
			f->i++;
	}
	if (f->precision_specified)
		f->space = 0;
}

void		ft_width(const char *format, t_struct *f)
{
	if (ft_isdigit(format[f->i]))
	{
		f->width = ft_atoi(&format[f->i]);
		while (ft_isdigit(format[f->i]))
			f->i++;
	}
}

void		ft_flags(const char *format, t_struct *f)
{
	while (ft_strchr("-+ 0#", format[f->i]))
	{
		if (format[f->i] == '-')
			f->minus = 1;
		else if (format[f->i] == '+')
			f->plus = 1;
		else if (format[f->i] == ' ')
			f->space = 1;
		else if (format[f->i] == '0')
			f->zero = 1;
		else if (format[f->i] == '#')
			f->hash = 1;
		f->i++;
	}
	if (f->plus)
		f->space = 0;
}

void		ft_process_modifiers(const char *format, t_struct *f)
{
	ft_flags(format, f);
	ft_width(format, f);
	ft_precision(format, f);
	ft_length(format, f);
}
