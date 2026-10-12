/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:34:51 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/12 17:36:03 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static void	free_split(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static void	print_split(char **arr)
{
	size_t	i;

	printf("[");
	i = 0;
	while (arr[i])
	{
		printf("\"%s\", ", arr[i]);
		i++;
	}
	printf("NULL]");
}

/* expected is a NULL-terminated list of words */
static int	check_split(const char *s, char c, const char **expected, int line)
{
	char	**got;
	size_t	i;

	got = ft_split(s, c);
	if (!got)
	{
		printf(RED "  KO" RESET " test on line %d: returned NULL\n", line);
		return (1);
	}
	i = 0;
	while (expected[i] && got[i] && strcmp(expected[i], got[i]) == 0)
		i++;
	if (expected[i] || got[i])
	{
		printf(RED "  KO" RESET " test on line %d: split(\"%s\", '%c') "
			"wrong at index %zu, got ", line, s, c ? c : '0', i);
		print_split(got);
		printf("\n");
		free_split(got);
		return (1);
	}
	free_split(got);
	return (0);
}

int	test_split(void)
{
	int			errors;
	const char	*t1[] = {"Hello", "World", "42", NULL};
	const char	*t2[] = {"Hello", "World", NULL};
	const char	*t3[] = {"a", "b", "c", NULL};
	const char	*t4[] = {"Hello", NULL};
	const char	*t5[] = {NULL};
	const char	*t6[] = {"\t\nabc", "def", NULL};
	const char	*t7[] = {"hello world", "foo bar", NULL};
	const char	*t8[] = {"a", NULL};
	const char	*t9[] = {"1", "2", "3", "4", "5", NULL};

	errors = 0;
	errors += check_split("Hello World 42", ' ', t1, __LINE__);
	errors += check_split("  Hello   World  ", ' ', t2, __LINE__);
	errors += check_split("a,b,,c", ',', t3, __LINE__);
	errors += check_split(",,,a,,b,,,c,,,", ',', t3, __LINE__);
	errors += check_split("Hello", ' ', t4, __LINE__);
	errors += check_split("Hello", '\0', t4, __LINE__);
	errors += check_split("", ' ', t5, __LINE__);
	errors += check_split("     ", ' ', t5, __LINE__);
	errors += check_split("", '\0', t5, __LINE__);
	errors += check_split("   \t\nabc  def ", ' ', t6, __LINE__);
	errors += check_split("hello world,foo bar", ',', t7, __LINE__);
	errors += check_split("a", ' ', t8, __LINE__);
	errors += check_split(" a ", ' ', t8, __LINE__);
	errors += check_split("1-2-3-4-5", '-', t9, __LINE__);
	if (ft_split(NULL, ' ') != NULL)
	{
		printf(RED "  KO" RESET " split(NULL, ' ') should return NULL\n");
		errors++;
	}
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_split\n");
	else
		printf(RED "[KO]" RESET " ft_split: %d errors\n", errors);
	return (errors);
}
