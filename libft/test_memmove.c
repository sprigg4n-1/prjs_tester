/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 15:13:44 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 15:14:10 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"
#define BUF_SIZE 20

static int	check_memmove(size_t dst_off, size_t src_off, size_t n)
{
	char	buf1[BUF_SIZE];
	char	buf2[BUF_SIZE];
	void	*ret;
	size_t	i;

	memcpy(buf1, "abcdefghijklmnopqrs", BUF_SIZE);
	memcpy(buf2, "abcdefghijklmnopqrs", BUF_SIZE);
	memmove(buf1 + dst_off, buf1 + src_off, n);
	ret = ft_memmove(buf2 + dst_off, buf2 + src_off, n);
	if (ret != buf2 + dst_off)
	{
		printf(RED "  KO" RESET " dst=+%zu src=+%zu n=%zu: must return dst\n",
			dst_off, src_off, n);
		return (1);
	}
	if (memcmp(buf1, buf2, BUF_SIZE) != 0)
	{
		i = 0;
		while (buf1[i] == buf2[i])
			i++;
		printf(RED "  KO" RESET " dst=+%zu src=+%zu n=%zu: byte %zu expected %d, got %d\n",
			dst_off, src_off, n, i, (unsigned char)buf1[i], (unsigned char)buf2[i]);
		return (1);
	}
	return (0);
}

int	test_memmove(void)
{
	int		errors;
	char	src[] = "no overlap";
	char	d1[BUF_SIZE];
	char	d2[BUF_SIZE];

	errors = 0;
	memset(d1, 'Z', BUF_SIZE);
	memset(d2, 'Z', BUF_SIZE);
	memmove(d1, src, sizeof(src));
	ft_memmove(d2, src, sizeof(src));
	if (memcmp(d1, d2, BUF_SIZE) != 0)
	{
		printf(RED "  KO" RESET " without overlap\n");
		errors++;
	}
	errors += check_memmove(2, 0, 8);
	errors += check_memmove(0, 2, 8);
	errors += check_memmove(1, 0, 15);
	errors += check_memmove(0, 1, 15);
	errors += check_memmove(5, 5, 10);
	errors += check_memmove(3, 0, 0);
	errors += check_memmove(8, 0, 12);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_memmove\n");
	else
		printf(RED "[KO]" RESET " ft_memmove: %d errors\n", errors);
	return (errors);
}
