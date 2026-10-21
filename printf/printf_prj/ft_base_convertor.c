/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_convertor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 13:21:44 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/21 18:17:37 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_base_convertor(unsigned long nbr, int base_len, char *base)
{
	int		len;
	int		wr_len;
	char	c;

	c = base[nbr % base_len];
	len = 0;
	if (nbr / base_len)
	{
		len += ft_base_convertor(nbr / base_len, base_len, base);
		if (len == -1)
			return (-1);
	}
	wr_len = write(1, &c, 1);
	if (wr_len == -1)
		return (-1);
	return (len + wr_len);
}
