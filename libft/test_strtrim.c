/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 12:59:19 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/12 13:00:00 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static int	check_strtrim(const char *s1, const char *set, const char *expected)
{
	char	*got;

	got = ft_strtrim(s1, set);
	if (!got)
	{
		printf(RED "  KO" RESET " strtrim(\"%s\", \"%s\"): returned NULL, "
			"expected \"%s\"\n", s1, set, expected);
		return (1);
	}
	if (got == s1)
	{
		printf(RED "  KO" RESET " strtrim(\"%s\", \"%s\"): returned s1, "
			"must be new memory\n", s1, set);
		return (1);
	}
	if (strcmp(got, expected) != 0)
	{
		printf(RED "  KO" RESET " strtrim(\"%s\", \"%s\"): expected \"%s\", "
			"got \"%s\"\n", s1, set, expected, got);
		free(got);
		return (1);
	}
	free(got);
	return (0);
}

static int	check_unchanged(void)
{
	char	s1[] = "  keep me  ";
	char	*got;
	int		errors;

	errors = 0;
	got = ft_strtrim(s1, " ");
	if (strcmp(s1, "  keep me  ") != 0)
	{
		printf(RED "  KO" RESET " strtrim changed the original string\n");
		errors = 1;
	}
	free(got);
	return (errors);
}

int	test_strtrim(void)
{
	int	errors;

	errors = 0;
	errors += check_strtrim("   Hello World   ", " ", "Hello World");
	errors += check_strtrim("xxabcxx", "x", "abc");
	errors += check_strtrim("--==Hello==--", "-=", "Hello");
	errors += check_strtrim("abcHelloabc", "abc", "Hello");
	errors += check_strtrim("cbaHellocab", "abc", "Hello");
	errors += check_strtrim("a-b-c", "-", "a-b-c");
	errors += check_strtrim("  Hello", " ", "Hello");
	errors += check_strtrim("Hello  ", " ", "Hello");
	errors += check_strtrim(" \t\n Hello \n\t ", " \t\n", "Hello");
	errors += check_strtrim("xxxx", "x", "");
	errors += check_strtrim("x", "x", "");
	errors += check_strtrim("", "x", "");
	errors += check_strtrim("", "", "");
	errors += check_strtrim("Hello", "", "Hello");
	errors += check_strtrim("Hello", "xyz", "Hello");
	errors += check_strtrim("a", "b", "a");
	errors += check_strtrim("xHx", "x", "H");
	errors += check_unchanged();
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_strtrim\n");
	else
		printf(RED "[KO]" RESET " ft_strtrim: %d errors\n", errors);
	return (errors);
}
