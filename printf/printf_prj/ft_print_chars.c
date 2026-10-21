/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 13:21:33 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/21 13:40:06 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_print_chars(va_list *ptr, char c)
{
	if (c == '%')
		return (ft_putchar(c));
	if (c == 'c')
		return (ft_putchar(va_arg(*ptr, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*ptr, char *)));
	return (0);
}
