/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 23:34:42 by romankovini       #+#    #+#             */
/*   Updated: 2026/10/20 13:13:12 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(va_list *ptr, char c)
{
	int		len;
	char	*str;

	len = 0;
	if (c == 's')
	{
		str = va_arg(*ptr, char *);
		if (str == NULL)
		{
			ft_putstr_fd("(null)", 1);
			len = 6;
		}
		else
		{
			ft_putstr_fd(str, 1);
			len = ft_strlen(str);
		}

	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ptr;

	count = 0;
	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			ft_conversion(&ptr, *format);
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(ptr);
	return (count);
}

int	main(void)
{
	ft_printf("I want to say: %s %s", "HELLO", NULL);
	return (0);
}
