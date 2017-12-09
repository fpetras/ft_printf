/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 07:29:30 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/09 11:01:04 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int			ft_uitoa_base_pf(uintmax_t value, int base, char letter)
{
	int			len;
	uintmax_t	value2;
	char		*radix;
	char		*result;

	len = 1;
	value2 = value;
	while (value2 /= base)
		len++;
	if (letter == 'X')
		radix = ft_strdup("0123456789ABCDEF");
	else
		radix = ft_strdup("0123456789abcdef");
	result = (char*)malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	while (len-- > 0)
	{
		result[len] = radix[value % base];
		value /= base;
	}
	len = ft_strlen(result);
	write(1, result, len);
	free(radix);
	free(result);
	return (len);
}
