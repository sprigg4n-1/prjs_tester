/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:19:55 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 16:26:25 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static int	check_strchr(const char *s, int c)
{
	char	*exp;
	char	*got;

	exp = strchr(s, c);
	got = ft_strchr(s, c);
	if (exp == got)
		return (0);
	if (exp && got)
		printf(RED "  KO" RESET " s=\"%s\" c=%d: expected s + %td, got s + %td\n",
			s, c, exp - s, got - s);
	else if (exp)
		printf(RED "  KO" RESET " s=\"%s\" c=%d: expected s + %td, got NULL\n",
			s, c, exp - s);
	else
		printf(RED "  KO" RESET " s=\"%s\" c=%d: expected NULL, got s + %td\n",
			s, c, got - s);
	return (1);
}

int	test_strchr(void)
{
	int	errors;

	errors = 0;
	errors += check_strchr("abcabc", 'b');
	errors += check_strchr("abcabc", 'a');
	errors += check_strchr("abcabc", 'c');
	errors += check_strchr("abcabc", 'z');
	errors += check_strchr("abcabc", '\0');
	errors += check_strchr("", '\0');
	errors += check_strchr("", 'a');
	errors += check_strchr("abc", 'a' + 256);
	errors += check_strchr("x\310y", 200);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_strchr\n");
	else
		printf(RED "[KO]" RESET " ft_strchr: %d errors\n", errors);
	return (errors);
}
