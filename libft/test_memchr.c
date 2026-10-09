/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:20:57 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 16:33:29 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static int	check_memchr(const char *s, int c, size_t n)
{
	char	*exp;
	char	*got;

	exp = memchr(s, c, n);
	got = ft_memchr(s, c, n);
	if (exp == got)
		return (0);
	if (exp && got)
		printf(RED "  KO" RESET " c=%d n=%zu: expected s + %td, got s + %td\n",
			c, n, exp - s, got - s);
	else if (exp)
		printf(RED "  KO" RESET " c=%d n=%zu: expected s + %td, got NULL\n",
			c, n, exp - s);
	else
		printf(RED "  KO" RESET " c=%d n=%zu: expected NULL, got s + %td\n",
			c, n, got - s);
	return (1);
}

int	test_memchr(void)
{
	int	errors;

	errors = 0;
	errors += check_memchr("abcabc", 'b', 6);
	errors += check_memchr("abcabc", 'z', 6);
	errors += check_memchr("abcabc", 'c', 2);
	errors += check_memchr("abcabc", 'c', 3);
	errors += check_memchr("ab\0cd", 'c', 5);
	errors += check_memchr("ab\0cd", 'c', 3);
	errors += check_memchr("ab\0cd", '\0', 5);
	errors += check_memchr("abc", 'a' + 256, 3);
	errors += check_memchr("x\310y", 200, 3);
	errors += check_memchr("abc", 'a', 0);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_memchr\n");
	else
		printf(RED "[KO]" RESET " ft_memchr: %d errors\n", errors);
	return (errors);
}
