/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:45:06 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/11 13:28:52 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwstr_pf(wchar_t *wstr, t_struct *f, int max)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (wstr[i])
	{
		if (wstr[i] <= 127)
			size += 1;
		else if (wstr[i] >= 128 && wstr[i] <= 2047)
			size += 2;
		else if (wstr[i] >= 2048 && wstr[i] <= 65535)
			size += 3;
		else if (wstr[i] >= 65536 && wstr[i] <= 1114111)
			size += 4;
		if (size <= max)
			ft_putwchar_pf(wstr[i], f);
		else
			break ;
		i++;
	}
}
