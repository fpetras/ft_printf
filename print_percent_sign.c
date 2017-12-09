/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent_sign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 10:02:15 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/09 10:12:11 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_percent_sign_left_align(t_struct *f)
{
	f->len += write(1, "%", 1);
	while (f->width > 1)
	{
		f->len += write(1, " ", 1);
		f->width--;
	}
}

static void	ft_print_percent_sign_right_align(t_struct *f)
{
	while (f->width > 1)
	{
		f->len += write(1, " ", 1);
		f->width--;
	}
	f->len += write(1, "%", 1);
}

void		ft_print_percent_sign(char type, t_struct *f)
{
	if (type == '%')
	{
		if (f->minus)
			ft_print_percent_sign_left_align(f);
		else
			ft_print_percent_sign_right_align(f);
	}
}