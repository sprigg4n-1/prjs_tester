/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:21:26 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 16:41:02 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static int	check_strdup(const char *s, int line)
{
	char	*copy;

	copy = ft_strdup(s);
	if (!copy)
	{
		printf(RED "  KO" RESET " test on line %d: returned NULL\n", line);
		return (1);
	}
	if (copy == s)
	{
		printf(RED "  KO" RESET " test on line %d: returned the same pointer, "
			"must be a new copy\n", line);
		return (1);
	}
	if (strcmp(copy, s) != 0)
	{
		printf(RED "  KO" RESET " test on line %d: copy differs from original\n",
			line);
		free(copy);
		return (1);
	}
	free(copy);
	return (0);
}

static int	check_independent(void)
{
	char	src[] = "change me";
	char	*copy;

	copy = ft_strdup(src);
	if (!copy)
		return (1);
	copy[0] = 'X';
	if (src[0] != 'c')
	{
		printf(RED "  KO" RESET " changing the copy changed the original\n");
		free(copy);
		return (1);
	}
	free(copy);
	return (0);
}

int	test_strdup(void)
{
	int		errors;
	char	big[5001];

	errors = 0;
	errors += check_strdup("Hello", __LINE__);
	errors += check_strdup("", __LINE__);
	errors += check_strdup("a", __LINE__);
	errors += check_strdup("Hello, World!", __LINE__);
	errors += check_strdup("ab\200\377", __LINE__);
	memset(big, 'q', 5000);
	big[5000] = '\0';
	errors += check_strdup(big, __LINE__);
	errors += check_independent();
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_strdup\n");
	else
		printf(RED "[KO]" RESET " ft_strdup: %d errors\n", errors);
	return (errors);
}
