/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 11:55:41 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/08 11:56:09 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

int	test_isprint(void)
{
	int	c;
	int	errors;
	int	expected;
	int	got;

	errors = 0;
	c = -1;
	while (c <= 255)
	{
		expected = !!isprint(c);
		got = ft_isprint(c);
		if (got != expected)
		{
			printf(RED "  KO" RESET " c=%d: expected %d, got %d\n",
				c, expected, got);
			errors++;
		}
		c++;
	}
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_isprint\n");
	else
		printf(RED "[KO]" RESET " ft_isprint: %d errors\n", errors);
	return (errors);
}
