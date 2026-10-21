/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:15:04 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/21 14:27:31 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_p(void *p)
{
	int	write_len;

	if (!p)
		return (write(1, "(nil)", 5));
	write_len = write(1, "0x", 2);
	return (write_len + ft_base_convertor((unsigned long)p, 16,
			"0123456789abcdef"));
}

int	ft_print_hex(va_list *ptr, char c)
{
	if (c == 'x')
		return (ft_base_convertor(va_arg(*ptr, unsigned int), 16,
				"0123456789abcdef"));
	if (c == 'X')
		return (ft_base_convertor(va_arg(*ptr, unsigned int), 16,
				"0123456789ABCDEF"));
	if (c == 'p')
		return (ft_print_p(va_arg(*ptr, void *)));
	return (0);
}
