/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 13:21:44 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/20 15:02:05 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
z
static	void	base_convertor(long nbr, int base_len, char *base)
{
	char	c;

	c = base[nbr % base_len];
	if (nbr / base_len)
	{
		base_convertor(nbr / base_len, base_len, base);
	}
	write(1, &c, 1);
}
