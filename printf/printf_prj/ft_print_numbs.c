/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 13:21:31 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/20 13:34:25 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int n)
{
	long	nl;
	char	c;

	nl = (long)n;
	if (nl < 0)
	{
		write(1, "-", 1);
		nl *= -1;
	}
	if (nl > 9)
		ft_putnbr(nl / 10);
	c = nl % 10 + 48;
	write(1, &c, 1);
}
