#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static char	same(unsigned int i, char c)
{
	(void)i;
	return (c);
}

static char	to_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static char	upper_even(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static char	add_index(unsigned int i, char c)
{
	return (c + i);
}

static int	check_strmapi(const char *s, char (*f)(unsigned int, char),
	const char *expected, int line)
{
	char	*got;

	got = ft_strmapi(s, f);
	if (!got)
	{
		printf(RED "  KO" RESET " test on line %d: returned NULL, expected "
			"\"%s\"\n", line, expected);
		return (1);
	}
	if (got == s)
	{
		printf(RED "  KO" RESET " test on line %d: returned s, must be new "
			"memory\n", line);
		return (1);
	}
	if (strcmp(got, expected) != 0)
	{
		printf(RED "  KO" RESET " test on line %d: expected \"%s\", got "
			"\"%s\"\n", line, expected, got);
		free(got);
		return (1);
	}
	free(got);
	return (0);
}

static int	check_unchanged(void)
{
	char	s[] = "hello";
	char	*got;
	int		errors;

	errors = 0;
	got = ft_strmapi(s, to_upper);
	if (strcmp(s, "hello") != 0)
	{
		printf(RED "  KO" RESET " strmapi changed the original string\n");
		errors = 1;
	}
	free(got);
	return (errors);
}

int	test_strmapi(void)
{
	int	errors;

	errors = 0;
	errors += check_strmapi("hello", same, "hello", __LINE__);
	errors += check_strmapi("hello", to_upper, "HELLO", __LINE__);
	errors += check_strmapi("Hello, World!", to_upper, "HELLO, WORLD!", __LINE__);
	errors += check_strmapi("hello", upper_even, "HeLlO", __LINE__);
	errors += check_strmapi("aaaa", add_index, "abcd", __LINE__);
	errors += check_strmapi("a", add_index, "a", __LINE__);
	errors += check_strmapi("", to_upper, "", __LINE__);
	errors += check_unchanged();
	if (ft_strmapi(NULL, to_upper) != NULL)
	{
		printf(RED "  KO" RESET " strmapi(NULL, f) should return NULL\n");
		errors++;
	}
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_strmapi\n");
	else
		printf(RED "[KO]" RESET " ft_strmapi: %d errors\n", errors);
	return (errors);
}
