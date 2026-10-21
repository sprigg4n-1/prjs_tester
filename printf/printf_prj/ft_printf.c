/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 23:34:42 by romankovini       #+#    #+#             */
/*   Updated: 2026/10/21 18:28:44 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_conversion(va_list *ptr, char c)
{
	if (c == 's' || c == '%' || c == 'c')
		return (ft_print_chars(ptr, c));
	if (c == 'd' || c == 'i' || c == 'u')
		return (ft_print_numbs(ptr, c));
	if (c == 'x' || c == 'X' || c == 'p')
		return (ft_print_hex(ptr, c));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		len;
	va_list	ptr;

	count = 0;
	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			len = ft_conversion(&ptr, *format);
		}
		else
			len = write(1, format, 1);
		if (len == -1)
		{
			va_end(ptr);
			return (-1);
		}
		count += len;
		format++;
	}
	va_end(ptr);
	return (count);
}
