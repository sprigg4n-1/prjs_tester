/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 23:34:42 by romankovini       #+#    #+#             */
/*   Updated: 2026/10/19 14:19:51 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ptr;
	int		ch_nmb;
	char	*str;

	count = 0;
	va_start(ptr, format);
	while (*format)
	{
		if (*format == 'd')
		{
			ch_nmb = va_arg(ptr, int);
			ft_putnbr_fd(ch_nmb, 1);
		}
		else if (*format == 'c')
		{
			ch_nmb = va_arg(ptr, int);
			ft_putchar_fd(ch_nmb, 1);
		}
		else if (*format == 's')
		{
			str = va_arg(ptr, char *);
			ft_putstr_fd(str, 1);
		}
		write(1, "\n", 1);
		format++;
	}
	va_end(ptr);
	return (count);
}

int	main(void)
{
	ft_printf("ddccss", 32, 42, 'A', 'B', "HELLO", "WORLD");
	return (0);
}
