/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 15:03:25 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 15:03:38 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"
#define BUF_SIZE 20

static int	check_memset(int c, size_t n)
{
	char	buf1[BUF_SIZE];
	char	buf2[BUF_SIZE];
	void	*ret;
	size_t	i;

	memcpy(buf1, "abcdefghijklmnopqrs", BUF_SIZE);
	memcpy(buf2, "abcdefghijklmnopqrs", BUF_SIZE);
	memset(buf1, c, n);
	ret = ft_memset(buf2, c, n);
	if (ret != buf2)
	{
		printf(RED "  KO" RESET " c=%d n=%zu: wrong return pointer\n", c, n);
		return (1);
	}
	if (memcmp(buf1, buf2, BUF_SIZE) != 0)
	{
		i = 0;
		while (buf1[i] == buf2[i])
			i++;
		printf(RED "  KO" RESET " c=%d n=%zu: byte %zu expected %d, got %d\n",
			c, n, i, (unsigned char)buf1[i], (unsigned char)buf2[i]);
		return (1);
	}
	return (0);
}

int	test_memset(void)
{
	int	errors;

	errors = 0;
	errors += check_memset('x', 5);
	errors += check_memset('x', 0);
	errors += check_memset(0, 10);
	errors += check_memset(300, 5);
	errors += check_memset(-1, 5);
	errors += check_memset('A', BUF_SIZE);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_memset\n");
	else
		printf(RED "[KO]" RESET " ft_memset: %d errors\n", errors);
	return (errors);
}
