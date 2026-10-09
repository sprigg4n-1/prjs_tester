/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 15:07:17 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 15:07:58 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"
#define BUF_SIZE 20

static int	check_bzero(size_t n)
{
	char	buf1[BUF_SIZE];
	char	buf2[BUF_SIZE];
	size_t	i;

	memcpy(buf1, "abcdefghijklmnopqrs", BUF_SIZE);
	memcpy(buf2, "abcdefghijklmnopqrs", BUF_SIZE);
	bzero(buf1, n);
	ft_bzero(buf2, n);
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

int	test_bzero(void)
{
	int	errors;

	errors = 0;
	errors += check_bzero(0);
	errors += check_bzero(1);
	errors += check_bzero(5);
	errors += check_bzero(10);
	errors += check_bzero(BUF_SIZE);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_bzero\n");
	else
		printf(RED "[KO]" RESET " ft_bzero: %d errors\n", errors);
	return (errors);
}
