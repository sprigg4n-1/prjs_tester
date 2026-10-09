/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:20:52 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 16:36:17 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#ifdef __linux__
# include <bsd/string.h>
#endif
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static int	check_strnstr(const char *big, const char *little, size_t len)
{
	char	*exp;
	char	*got;

	exp = strnstr(big, little, len);
	got = ft_strnstr(big, little, len);
	if (exp == got)
		return (0);
	if (exp && got)
		printf(RED "  KO" RESET " big=\"%s\" little=\"%s\" len=%zu: expected big + %td, got big + %td\n",
			big, little, len, exp - big, got - big);
	else if (exp)
		printf(RED "  KO" RESET " big=\"%s\" little=\"%s\" len=%zu: expected big + %td, got NULL\n",
			big, little, len, exp - big);
	else
		printf(RED "  KO" RESET " big=\"%s\" little=\"%s\" len=%zu: expected NULL, got big + %td\n",
			big, little, len, got - big);
	return (1);
}

int	test_strnstr(void)
{
	int	errors;

	errors = 0;
	errors += check_strnstr("Foo Bar Baz", "Bar", 20);
	errors += check_strnstr("Foo Bar Baz", "Bar", 7);
	errors += check_strnstr("Foo Bar Baz", "Bar", 6);
	errors += check_strnstr("Foo Bar Baz", "Bar", 4);
	errors += check_strnstr("Foo Bar Baz", "Baz", 11);
	errors += check_strnstr("Foo Bar Baz", "Foo", 3);
	errors += check_strnstr("Foo Bar Baz", "", 0);
	errors += check_strnstr("Foo Bar Baz", "", 5);
	errors += check_strnstr("", "", 0);
	errors += check_strnstr("", "a", 5);
	errors += check_strnstr("aaab", "ab", 4);
	errors += check_strnstr("aaab", "ab", 3);
	errors += check_strnstr("abc", "abcd", 10);
	errors += check_strnstr("abc", "c", 0);
	errors += check_strnstr("abcabc", "abc", 6);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_strnstr\n");
	else
		printf(RED "[KO]" RESET " ft_strnstr: %d errors\n", errors);
	return (errors);
}
