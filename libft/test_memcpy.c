/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 15:11:41 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 15:12:15 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"
#define BUF_SIZE 20

static int	check_memcpy(const void *src, size_t n)
{
	char	buf1[BUF_SIZE];
	char	buf2[BUF_SIZE];
	void	*ret;
	size_t	i;

	memset(buf1, 'Z', BUF_SIZE);
	memset(buf2, 'Z', BUF_SIZE);
	memcpy(buf1, src, n);
	ret = ft_memcpy(buf2, src, n);
	if (ret != buf2)
	{
		printf(RED "  KO" RESET " n=%zu: must return dst\n", n);
		return (1);
	}
	if (memcmp(buf1, buf2, BUF_SIZE) != 0)
	{
		i = 0;
		while (buf1[i] == buf2[i])
			i++;
		printf(RED "  KO" RESET " n=%zu: byte %zu expected %d, got %d\n",
			n, i, (unsigned char)buf1[i], (unsigned char)buf2[i]);
		return (1);
	}
	return (0);
}

int	test_memcpy(void)
{
	int	errors;

	errors = 0;
	errors += check_memcpy("Hello", 6);
	errors += check_memcpy("Hello", 3);
	errors += check_memcpy("Hello", 0);
	errors += check_memcpy("ab\0cd", 5);
	errors += check_memcpy("\200\377\001", 3);
	errors += check_memcpy("abcdefghijklmnopqrs", BUF_SIZE);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_memcpy\n");
	else
		printf(RED "[KO]" RESET " ft_memcpy: %d errors\n", errors);
	return (errors);
}
