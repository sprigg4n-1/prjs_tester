/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:20:58 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 16:34:48 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static int	sign(int n)
{
	if (n > 0)
		return (1);
	if (n < 0)
		return (-1);
	return (0);
}

static int	check_memcmp(const char *s1, const char *s2, size_t n, int line)
{
	int	exp;
	int	got;

	exp = sign(memcmp(s1, s2, n));
	got = sign(ft_memcmp(s1, s2, n));
	if (exp == got)
		return (0);
	printf(RED "  KO" RESET " test on line %d (n=%zu): expected sign %d, got sign %d\n",
		line, n, exp, got);
	return (1);
}

int	test_memcmp(void)
{
	int	errors;

	errors = 0;
	errors += check_memcmp("abc", "abc", 3, __LINE__);
	errors += check_memcmp("abc", "abd", 3, __LINE__);
	errors += check_memcmp("abd", "abc", 3, __LINE__);
	errors += check_memcmp("abc", "abd", 2, __LINE__);
	errors += check_memcmp("abc\0x", "abc\0y", 5, __LINE__);
	errors += check_memcmp("abc\0y", "abc\0x", 5, __LINE__);
	errors += check_memcmp("abc\0x", "abc\0x", 5, __LINE__);
	errors += check_memcmp("\200", "\0", 1, __LINE__);
	errors += check_memcmp("\0", "\200", 1, __LINE__);
	errors += check_memcmp("\377", "\001", 1, __LINE__);
	errors += check_memcmp("abc", "xyz", 0, __LINE__);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_memcmp\n");
	else
		printf(RED "[KO]" RESET " ft_memcmp: %d errors\n", errors);
	return (errors);
}
