/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 23:34:42 by romankovini       #+#    #+#             */
/*   Updated: 2026/10/21 14:28:24 by rkovinia         ###   ########.fr       */
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
	va_list	ptr;

	count = 0;
	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			count += ft_conversion(&ptr, *format);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ptr);
	return (count);
}

int	main(void)
{
	int		a;
	int		b;
	int		x;
	char	*m;

	x = 42;
	m = malloc(10);

	a = printf("[%c|%s|%%|%u|%u|%u]\n", 'A', "hello", 0, 42, -1);
	b = ft_printf("[%c|%s|%%|%u|%u|%u]\n", 'A', "hello", 0, 42, -1);
	printf("printf: %d, ft_printf: %d\n\n", a, b);

	a = printf("[%d|%d|%d|%d|%d|%d]\n", 0, 42, -42, -1, 2147483647, -2147483647 - 1);
	b = ft_printf("[%d|%d|%d|%d|%d|%d]\n", 0, 42, -42, -1, 2147483647, -2147483647 - 1);
	printf("printf: %d, ft_printf: %d\n\n", a, b);

	a = printf("[%i|%i|%i|%i|%i]\n", 0, 7, -7, 0x2A, 052);
	b = ft_printf("[%i|%i|%i|%i|%i]\n", 0, 7, -7, 0x2A, 052);
	printf("printf: %d, ft_printf: %d\n\n", a, b);

	a = printf("[%x|%x|%x|%x|%x]\n", 0, 42, 255, -1, 0xDEADBEEF);
	b = ft_printf("[%x|%x|%x|%x|%x]\n", 0, 42, 255, -1, 0xDEADBEEF);
	printf("printf: %d, ft_printf: %d\n\n", a, b);

	a = printf("[%X|%X|%X|%X|%X]\n", 0, 42, 255, -1, 0xDEADBEEF);
	b = ft_printf("[%X|%X|%X|%X|%X]\n", 0, 42, 255, -1, 0xDEADBEEF);
	printf("printf: %d, ft_printf: %d\n\n", a, b);

	a = printf("[%x|%X|%u|%d]\n", 4294967295u, 2147483647, 16, -16);
	b = ft_printf("[%x|%X|%u|%d]\n", 4294967295u, 2147483647, 16, -16);
	printf("printf: %d, ft_printf: %d\n\n", a, b);

	a = printf("[%p|%p|%p]\n", &x, m, "hi");
	b = ft_printf("[%p|%p|%p]\n", &x, m, "hi");
	printf("printf: %d, ft_printf: %d\n\n", a, b);

	a = printf("[%p]\n", NULL);
	b = ft_printf("[%p]\n", NULL);
	printf("printf: %d, ft_printf: %d\n\n", a, b);

	a = printf("[%p|%p]\n", (void *)1, (void *)-1);
	b = ft_printf("[%p|%p]\n", (void *)1, (void *)-1);
	printf("printf: %d, ft_printf: %d\n\n", a, b);

	free(m);
	return (0);
}
