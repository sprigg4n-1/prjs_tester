#include <stdio.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static unsigned int	g_calls;
static unsigned int	g_last_index;

static void	to_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

static void	upper_even(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

static void	add_index(unsigned int i, char *c)
{
	*c = *c + i;
}

static void	count_calls(unsigned int i, char *c)
{
	(void)c;
	g_calls++;
	g_last_index = i;
}

static int	check_striteri(const char *src, void (*f)(unsigned int, char *),
	const char *expected, int line)
{
	char	buf[64];

	strcpy(buf, src);
	ft_striteri(buf, f);
	if (strcmp(buf, expected) != 0)
	{
		printf(RED "  KO" RESET " test on line %d: \"%s\" -> expected \"%s\", "
			"got \"%s\"\n", line, src, expected, buf);
		return (1);
	}
	return (0);
}

static int	check_calls(const char *src, unsigned int expected_calls)
{
	char	buf[64];

	strcpy(buf, src);
	g_calls = 0;
	g_last_index = 0;
	ft_striteri(buf, count_calls);
	if (g_calls != expected_calls
		|| (expected_calls > 0 && g_last_index != expected_calls - 1))
	{
		printf(RED "  KO" RESET " \"%s\": f called %u times (last index %u), "
			"expected %u times\n", src, g_calls, g_last_index, expected_calls);
		return (1);
	}
	return (0);
}

int	test_striteri(void)
{
	int	errors;

	errors = 0;
	errors += check_striteri("hello", to_upper, "HELLO", __LINE__);
	errors += check_striteri("Hello, World!", to_upper, "HELLO, WORLD!",
			__LINE__);
	errors += check_striteri("hello", upper_even, "HeLlO", __LINE__);
	errors += check_striteri("aaaa", add_index, "abcd", __LINE__);
	errors += check_striteri("", to_upper, "", __LINE__);
	errors += check_calls("hello", 5);
	errors += check_calls("a", 1);
	errors += check_calls("", 0);
	ft_striteri(NULL, to_upper);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_striteri\n");
	else
		printf(RED "[KO]" RESET " ft_striteri: %d errors\n", errors);
	return (errors);
}
