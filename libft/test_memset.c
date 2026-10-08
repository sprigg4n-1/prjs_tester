/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 12:29:21 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/08 12:30:51 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

int	test_memset(void)
{
	int		errors;
	int		expected;
	int		got;

	errors = 0;

	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_memset\n");
	else
		printf(RED "[KO]" RESET " ft_memset: %d errors\n", errors);
	return (errors);
}
