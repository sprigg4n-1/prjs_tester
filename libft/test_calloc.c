/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:21:15 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 16:39:26 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static int	all_zero(const unsigned char *p, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (p[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

static int	check_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = ft_calloc(nmemb, size);
	if (!p)
	{
		printf(RED "  KO" RESET " calloc(%zu, %zu): returned NULL\n", nmemb, size);
		return (1);
	}
	if (!all_zero(p, nmemb * size))
	{
		printf(RED "  KO" RESET " calloc(%zu, %zu): memory is not all zeros\n",
			nmemb, size);
		free(p);
		return (1);
	}
	free(p);
	return (0);
}

static int	check_overflow(size_t nmemb, size_t size)
{
	void	*p;

	p = ft_calloc(nmemb, size);
	if (p)
	{
		printf(RED "  KO" RESET " calloc(%zu, %zu): expected NULL (overflow)\n",
			nmemb, size);
		free(p);
		return (1);
	}
	return (0);
}

int	test_calloc(void)
{
	int	errors;

	errors = 0;
	errors += check_calloc(5, sizeof(int));
	errors += check_calloc(1, 1);
	errors += check_calloc(1000, 1);
	errors += check_calloc(10, 100);
	errors += check_calloc(0, 5);
	errors += check_calloc(5, 0);
	errors += check_calloc(0, 0);
	errors += check_overflow(SIZE_MAX, 2);
	errors += check_overflow(SIZE_MAX / 2 + 2, 2);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_calloc\n");
	else
		printf(RED "[KO]" RESET " ft_calloc: %d errors\n", errors);
	return (errors);
}
