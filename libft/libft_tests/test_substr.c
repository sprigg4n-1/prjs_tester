#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static int	check_substr(const char *s, unsigned int start, size_t len,
	const char *expected)
{
	char	*got;

	got = ft_substr(s, start, len);
	if (!got)
	{
		printf(RED "  KO" RESET " substr(\"%s\", %u, %zu): returned NULL, "
			"expected \"%s\"\n", s, start, len, expected);
		return (1);
	}
	if (got == s + start)
	{
		printf(RED "  KO" RESET " substr(\"%s\", %u, %zu): returned a pointer "
			"into s, must be new memory\n", s, start, len);
		return (1);
	}
	if (strcmp(got, expected) != 0)
	{
		printf(RED "  KO" RESET " substr(\"%s\", %u, %zu): expected \"%s\", "
			"got \"%s\"\n", s, start, len, expected, got);
		free(got);
		return (1);
	}
	free(got);
	return (0);
}

int	test_substr(void)
{
	int	errors;

	errors = 0;
	errors += check_substr("Hello World", 6, 5, "World");
	errors += check_substr("Hello World", 0, 5, "Hello");
	errors += check_substr("Hello World", 0, 11, "Hello World");
	errors += check_substr("Hello World", 3, 4, "lo W");
	errors += check_substr("Hello", 2, 100, "llo");
	errors += check_substr("Hello", 2, SIZE_MAX, "llo");
	errors += check_substr("Hello", 4, 1, "o");
	errors += check_substr("Hello", 4, 10, "o");
	errors += check_substr("Hello", 5, 3, "");
	errors += check_substr("Hello", 10, 3, "");
	errors += check_substr("Hello", 4000000000u, 3, "");
	errors += check_substr("Hello", 1, 0, "");
	errors += check_substr("", 0, 5, "");
	errors += check_substr("", 1, 5, "");
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_substr\n");
	else
		printf(RED "[KO]" RESET " ft_substr: %d errors\n", errors);
	return (errors);
}
