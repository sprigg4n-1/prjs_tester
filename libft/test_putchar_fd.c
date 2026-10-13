/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putchar_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 10:23:49 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/13 10:24:33 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static int	check_putchar(char c)
{
	int		fds[2];
	char	buf[4];
	ssize_t	got;

	if (pipe(fds) == -1)
		return (1);
	ft_putchar_fd(c, fds[1]);
	close(fds[1]);
	got = read(fds[0], buf, sizeof(buf));
	close(fds[0]);
	if (got != 1 || buf[0] != c)
	{
		printf(RED "  KO" RESET " putchar_fd(%d): read %zd byte(s)",
			(unsigned char)c, got);
		if (got > 0)
			printf(", first = %d", (unsigned char)buf[0]);
		printf(", expected 1 byte = %d\n", (unsigned char)c);
		return (1);
	}
	return (0);
}

int	test_putchar_fd(void)
{
	int	errors;

	errors = 0;
	errors += check_putchar('a');
	errors += check_putchar('Z');
	errors += check_putchar('0');
	errors += check_putchar(' ');
	errors += check_putchar('\n');
	errors += check_putchar('\0');
	errors += check_putchar('\200');
	errors += check_putchar('\377');
	ft_putchar_fd('x', -1);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_putchar_fd\n");
	else
		printf(RED "[KO]" RESET " ft_putchar_fd: %d errors\n", errors);
	return (errors);
}
