/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 08:06:19 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/09 11:27:34 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_pointer_left_align(intmax_t nbr, t_struct *f)
{
	int nbrlen;

	nbrlen = ft_unsigned_nbr_len(nbr, 16) + 2;
	f->len += write(1, "0x", 2);
	f->len += ft_uitoa_base_pf(nbr, 16, 0);
	while (f->width > nbrlen)
	{
		f->len += write(1, " ", 1);
		f->width--;
	}
}

static void	ft_print_pointer_right_align(uintmax_t nbr, t_struct *f)
{
	int nbrlen;

	nbrlen = ft_unsigned_nbr_len(nbr, 16) + 2;
	while (f->width > nbrlen)
	{
		f->len += write(1, " ", 1);
		f->width--;
	}
	f->len += write(1, "0x", 2);
	f->len += ft_uitoa_base_pf(nbr, 16, 0);
}

void		ft_print_pointer(char type, t_struct *f, va_list ap)
{
	uintmax_t nbr;

	if (type == 'p')
		nbr = (long long)va_arg(ap, void *);
	if (f->minus)
		ft_print_pointer_left_align(nbr, f);
	else
		ft_print_pointer_right_align(nbr, f);
}
