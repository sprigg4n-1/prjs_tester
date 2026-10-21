/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 13:21:31 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/21 14:09:11 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(int n)
{
	long	nl;
	char	c;
	int		len;

	len = 0;
	nl = (long)n;
	if (nl < 0)
	{
		write(1, "-", 1);
		len += 1;
		nl *= -1;
	}
	if (nl > 9)
		len += ft_putnbr(nl / 10);
	c = nl % 10 + 48;
	return (len + write(1, &c, 1));
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
