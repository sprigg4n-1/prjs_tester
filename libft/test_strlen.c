/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 12:10:50 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/12 12:25:21 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

int	test_strlen(void)
{
	int			errors;
	size_t		expected;
	size_t		got;
	int			i;
	const char	*tests[] = {
		"", "a", "Hello, World",
		"         ", "abc\0def", "\t\n\v", "\200\377",
		"Lorem Ipsum is simply dummy text of the printing and typesetting "
		"industry. Lorem Ipsum has been the industry's standard dummy text "
		"ever since 1966, when designers at Letraset and James Mosley, the "
		"librarian at St Bride Printing Library in London, took a 1914 "
		"Cicero translation and scrambled it to make dummy text for "
		"Letraset's Body Type sheets.",
		NULL
	};

	errors = 0;
	i = 0;
	while (tests[i])
	{
		expected = strlen(tests[i]);
		got = ft_strlen(tests[i]);
		if (expected != got)
		{
			printf(RED "  KO" RESET " test %d: expected %zu, got %zu\n",
				i, expected, got);
			errors++;
		}
		i++;
	}
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_strlen\n");
	else
		printf(RED "[KO]" RESET " ft_strlen: %d errors\n", errors);
	return (errors);
}
