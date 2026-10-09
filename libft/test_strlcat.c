/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:13:48 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 16:15:23 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
# include <bsd/string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"
#define BUF_SIZE 16

static int	check_strlcat(const char *dst, const char *src, size_t size)
{
	char	buf1[BUF_SIZE];
	char	buf2[BUF_SIZE];
	size_t	ret1;
	size_t	ret2;
	size_t	i;

	memset(buf1, 'Z', BUF_SIZE);
	memset(buf2, 'Z', BUF_SIZE);
	strcpy(buf1, dst);
	strcpy(buf2, dst);
	ret1 = strlcat(buf1, src, size);
	ret2 = ft_strlcat(buf2, src, size);
	if (ret1 != ret2)
	{
		printf(RED "  KO" RESET " dst=\"%s\" src=\"%s\" size=%zu: expected return %zu, got %zu\n",
			dst, src, size, ret1, ret2);
		return (1);
	}
	if (memcmp(buf1, buf2, BUF_SIZE) != 0)
	{
		i = 0;
		while (buf1[i] == buf2[i])
			i++;
		printf(RED "  KO" RESET " dst=\"%s\" src=\"%s\" size=%zu: byte %zu expected %d, got %d\n",
			dst, src, size, i, (unsigned char)buf1[i], (unsigned char)buf2[i]);
		return (1);
	}
	return (0);
}

int	test_strlcat(void)
{
	int		errors;
	size_t	size;

	errors = 0;
	size = 0;
	while (size <= 12)
	{
		errors += check_strlcat("Hi", "abc", size);
		errors += check_strlcat("Hello", "World", size);
		errors += check_strlcat("", "abc", size);
		errors += check_strlcat("abc", "", size);
		size++;
	}
	errors += check_strlcat("Hello", "World!", BUF_SIZE);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_strlcat\n");
	else
		printf(RED "[KO]" RESET " ft_strlcat: %d errors\n", errors);
	return (errors);
}
