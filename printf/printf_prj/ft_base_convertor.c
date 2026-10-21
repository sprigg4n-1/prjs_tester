/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_convertor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 13:21:44 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/21 14:06:29 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_base_convertor(unsigned long nbr, int base_len, char *base)
{
	int		len;
	char	c;

	c = base[nbr % base_len];
	len = 0;
	if (nbr / base_len)
		len += ft_base_convertor(nbr / base_len, base_len, base);
	return (len + write(1, &c, 1));
}
