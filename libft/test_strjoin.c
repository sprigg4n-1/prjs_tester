#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static int	check_strjoin(const char *s1, const char *s2, const char *expected)
{
	char	*got;

	got = ft_strjoin(s1, s2);
	if (!got)
	{
		printf(RED "  KO" RESET " strjoin(\"%s\", \"%s\"): returned NULL\n",
			s1, s2);
		return (1);
	}
	if (got == s1 || got == s2)
	{
		printf(RED "  KO" RESET " strjoin(\"%s\", \"%s\"): returned an input "
			"pointer, must be new memory\n", s1, s2);
		return (1);
	}
	if (strcmp(got, expected) != 0)
	{
		printf(RED "  KO" RESET " strjoin(\"%s\", \"%s\"): expected \"%s\", "
			"got \"%s\"\n", s1, s2, expected, got);
		free(got);
		return (1);
	}
	free(got);
	return (0);
}

static int	check_unchanged(void)
{
	char	s1[] = "left";
	char	s2[] = "right";
	char	*got;
	int		errors;

	errors = 0;
	got = ft_strjoin(s1, s2);
	if (strcmp(s1, "left") != 0 || strcmp(s2, "right") != 0)
	{
		printf(RED "  KO" RESET " strjoin changed its input strings\n");
		errors = 1;
	}
	free(got);
	return (errors);
}

static int	check_long(void)
{
	char	a[3001];
	char	b[2001];
	char	*got;
	int		errors;

	memset(a, 'a', 3000);
	a[3000] = '\0';
	memset(b, 'b', 2000);
	b[2000] = '\0';
	got = ft_strjoin(a, b);
	if (!got)
		return (1);
	errors = 0;
	if (strlen(got) != 5000 || strncmp(got, a, 3000) != 0
		|| strcmp(got + 3000, b) != 0)
	{
		printf(RED "  KO" RESET " strjoin of 3000 + 2000 chars: wrong result "
			"(length %zu)\n", strlen(got));
		errors = 1;
	}
	free(got);
	return (errors);
}

int	test_strjoin(void)
{
	int	errors;

	errors = 0;
	errors += check_strjoin("Hello, ", "World", "Hello, World");
	errors += check_strjoin("abc", "def", "abcdef");
	errors += check_strjoin("abc", "", "abc");
	errors += check_strjoin("", "xyz", "xyz");
	errors += check_strjoin("", "", "");
	errors += check_strjoin("a", "b", "ab");
	errors += check_strjoin("  ", "\t\n", "  \t\n");
	errors += check_strjoin("\200\377", "\001", "\200\377\001");
	errors += check_unchanged();
	errors += check_long();
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_strjoin\n");
	else
		printf(RED "[KO]" RESET " ft_strjoin: %d errors\n", errors);
	return (errors);
}
