#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static int	check_itoa(int n)
{
	char	expected[16];
	char	*got;

	snprintf(expected, sizeof(expected), "%d", n);
	got = ft_itoa(n);
	if (!got)
	{
		printf(RED "  KO" RESET " itoa(%d): returned NULL, expected \"%s\"\n",
			n, expected);
		return (1);
	}
	if (strcmp(got, expected) != 0)
	{
		printf(RED "  KO" RESET " itoa(%d): expected \"%s\", got \"%s\"\n",
			n, expected, got);
		free(got);
		return (1);
	}
	free(got);
	return (0);
}

int	test_itoa(void)
{
	int	errors;
	int	n;

	errors = 0;
	errors += check_itoa(0);
	errors += check_itoa(5);
	errors += check_itoa(-5);
	errors += check_itoa(9);
	errors += check_itoa(-9);
	errors += check_itoa(10);
	errors += check_itoa(-10);
	errors += check_itoa(42);
	errors += check_itoa(-42);
	errors += check_itoa(100);
	errors += check_itoa(-100);
	errors += check_itoa(12345);
	errors += check_itoa(-12345);
	errors += check_itoa(1000000);
	errors += check_itoa(INT_MAX);
	errors += check_itoa(INT_MIN);
	errors += check_itoa(INT_MAX - 1);
	errors += check_itoa(INT_MIN + 1);
	n = -1000;
	while (n <= 1000)
	{
		errors += check_itoa(n);
		n++;
	}
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_itoa\n");
	else
		printf(RED "[KO]" RESET " ft_itoa: %d errors\n", errors);
	return (errors);
}
