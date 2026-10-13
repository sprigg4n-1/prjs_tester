/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 10:41:27 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/13 10:41:42 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

/* Writes n into a pipe with ft_putnbr_fd, then compares with printf's %d. */
static int	check_putnbr(int n)
{
	int		fds[2];
	char	buf[32];
	char	expected[16];
	ssize_t	r;
	size_t	total;

	if (pipe(fds) == -1)
		return (1);
	ft_putnbr_fd(n, fds[1]);
	close(fds[1]);
	total = 0;
	r = read(fds[0], buf, sizeof(buf) - 1);
	while (r > 0)
	{
		total += r;
		r = read(fds[0], buf + total, sizeof(buf) - 1 - total);
	}
	close(fds[0]);
	buf[total] = '\0';
	snprintf(expected, sizeof(expected), "%d", n);
	if (strcmp(buf, expected) != 0)
	{
		printf(RED "  KO" RESET " putnbr_fd(%d): wrote \"%s\", expected \"%s\"\n",
			n, buf, expected);
		return (1);
	}
	return (0);
}

int	test_putnbr_fd(void)
{
	int	errors;
	int	n;

	errors = 0;
	errors += check_putnbr(0);
	errors += check_putnbr(5);
	errors += check_putnbr(-5);
	errors += check_putnbr(9);
	errors += check_putnbr(-9);
	errors += check_putnbr(10);
	errors += check_putnbr(-10);
	errors += check_putnbr(42);
	errors += check_putnbr(-42);
	errors += check_putnbr(100);
	errors += check_putnbr(-100);
	errors += check_putnbr(1000000);
	errors += check_putnbr(INT_MAX);
	errors += check_putnbr(INT_MIN);
	errors += check_putnbr(INT_MAX - 1);
	errors += check_putnbr(INT_MIN + 1);
	n = -1000;
	while (n <= 1000)
	{
		errors += check_putnbr(n);
		n++;
	}
	ft_putnbr_fd(42, -1);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_putnbr_fd\n");
	else
		printf(RED "[KO]" RESET " ft_putnbr_fd: %d errors\n", errors);
	return (errors);
}
