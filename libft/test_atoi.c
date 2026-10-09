/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:21:19 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 16:38:34 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static int	check_atoi(const char *s, int line)
{
	int	exp;
	int	got;

	exp = atoi(s);
	got = ft_atoi(s);
	if (exp == got)
		return (0);
	printf(RED "  KO" RESET " test on line %d: expected %d, got %d\n",
		line, exp, got);
	return (1);
}

int	test_atoi(void)
{
	int	errors;

	errors = 0;
	errors += check_atoi("42", __LINE__);
	errors += check_atoi("-42", __LINE__);
	errors += check_atoi("+42", __LINE__);
	errors += check_atoi("   42", __LINE__);
	errors += check_atoi("\t\n\v\f\r 42", __LINE__);
	errors += check_atoi("  -17abc", __LINE__);
	errors += check_atoi("123 456", __LINE__);
	errors += check_atoi("0042", __LINE__);
	errors += check_atoi("0", __LINE__);
	errors += check_atoi("-0", __LINE__);
	errors += check_atoi("2147483647", __LINE__);
	errors += check_atoi("-2147483648", __LINE__);
	errors += check_atoi("abc42", __LINE__);
	errors += check_atoi("+-42", __LINE__);
	errors += check_atoi("-+42", __LINE__);
	errors += check_atoi("--42", __LINE__);
	errors += check_atoi("- 42", __LINE__);
	errors += check_atoi("", __LINE__);
	errors += check_atoi("   ", __LINE__);
	errors += check_atoi("\x1b 5", __LINE__);
	errors += check_atoi("1e5", __LINE__);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_atoi\n");
	else
		printf(RED "[KO]" RESET " ft_atoi: %d errors\n", errors);
	return (errors);
}
