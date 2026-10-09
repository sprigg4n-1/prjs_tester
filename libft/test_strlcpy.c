/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romankovinia <romankovinia@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 15:15:37 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 21:21:23 by romankovini      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#ifdef __linux__
# include <bsd/string.h>
#endif
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"
#define BUF_SIZE 16

static int	check_strlcpy(const char *src, size_t size)
{
	char	buf1[BUF_SIZE];
	char	buf2[BUF_SIZE];
	size_t	ret1;
	size_t	ret2;
	size_t	i;

	memset(buf1, 'Z', BUF_SIZE);
	memset(buf2, 'Z', BUF_SIZE);
	ret1 = strlcpy(buf1, src, size);
	ret2 = ft_strlcpy(buf2, src, size);
	if (ret1 != ret2)
	{
		printf(RED "  KO" RESET " src=\"%s\" size=%zu: expected return %zu, got %zu\n",
			src, size, ret1, ret2);
		return (1);
	}
	if (memcmp(buf1, buf2, BUF_SIZE) != 0)
	{
		i = 0;
		while (buf1[i] == buf2[i])
			i++;
		printf(RED "  KO" RESET " src=\"%s\" size=%zu: byte %zu expected %d, got %d\n",
			src, size, i, (unsigned char)buf1[i], (unsigned char)buf2[i]);
		return (1);
	}
	return (0);
}

int	test_strlcpy(void)
{
	int		errors;
	size_t	size;

	errors = 0;
	size = 0;
	while (size <= 8)
	{
		errors += check_strlcpy("Hello", size);
		errors += check_strlcpy("", size);
		size++;
	}
	errors += check_strlcpy("Hello World!", BUF_SIZE);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_strlcpy\n");
	else
		printf(RED "[KO]" RESET " ft_strlcpy: %d errors\n", errors);
	return (errors);
}
