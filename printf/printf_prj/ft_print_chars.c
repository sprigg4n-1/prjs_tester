/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 13:21:33 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/20 14:56:23 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_chars(va_list *ptr, char c)
{
	int		len;
	char	*str;
	char	chr;

	len = 0;
	if (c == '%')
	{
		ft_putchar_fd(c, 1);
		len = 1;
	}
	else if (c == 'c')
	{
		chr = va_arg(ptr, char);
		ft_putchar_fd(chr, 1);
		len = 1;
	}
	else if (c == 's')
	{
		str = va_arg(ptr, char *);
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
	}
	return (len);
}
