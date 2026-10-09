/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:20:10 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 16:46:47 by rkovinia         ###   ########.fr       */
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

static int	check_strncmp(const char *s1, const char *s2, size_t n)
{
	int	exp;
	int	got;

	exp = sign(strncmp(s1, s2, n));
	got = sign(ft_strncmp(s1, s2, n));
	if (exp == got)
		return (0);
	printf(RED "  KO" RESET " s1=\"%s\" s2=\"%s\" n=%zu: expected sign %d, got sign %d\n",
		s1, s2, n, exp, got);
	return (1);
}

int	test_strncmp(void)
{
	int	errors;

	errors = 0;
	errors += check_strncmp("abc", "abc", 3);
	errors += check_strncmp("abc", "abd", 3);
	errors += check_strncmp("abd", "abc", 3);
	errors += check_strncmp("abc", "abd", 2);
	errors += check_strncmp("abc", "abcdef", 6);
	errors += check_strncmp("abcdef", "abc", 6);
	errors += check_strncmp("abc", "abc", 100);
	errors += check_strncmp("abc\0x", "abc\0y", 5);
	errors += check_strncmp("\200", "\0", 1);
	errors += check_strncmp("a", "\200", 1);
	errors += check_strncmp("abc", "xyz", 0);
	errors += check_strncmp("", "", 1);
	errors += check_strncmp("", "a", 1);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_strncmp\n");
	else
		printf(RED "[KO]" RESET " ft_strncmp: %d errors\n", errors);
	return (errors);
}
