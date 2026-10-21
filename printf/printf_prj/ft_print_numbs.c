/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 13:21:31 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/21 18:24:05 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(int n)
{
	long	nl;
	int		len;
	int		num_l;

	len = 0;
	nl = (long)n;
	if (nl < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len += 1;
		nl *= -1;
	}
	num_l = ft_base_convertor(nl, 10, "0123456789");
	if (num_l == -1)
		return (-1);
	return (len + num_l);
}

int	ft_print_numbs(va_list *ptr, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*ptr, int)));
	if (c == 'u')
		return (ft_base_convertor(va_arg(*ptr, unsigned int), 10,
				"0123456789"));
	return (0);
}
