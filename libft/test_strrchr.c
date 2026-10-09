/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:20:02 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 16:28:48 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static int	check_strrchr(const char *s, int c)
{
	char	*exp;
	char	*got;

	exp = strrchr(s, c);
	got = ft_strrchr(s, c);
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

int	test_strrchr(void)
{
	int	errors;

	errors = 0;
	errors += check_strrchr("abcabc", 'b');
	errors += check_strrchr("abcabc", 'a');
	errors += check_strrchr("abcabc", 'c');
	errors += check_strrchr("abcabc", 'z');
	errors += check_strrchr("abcabc", '\0');
	errors += check_strrchr("", '\0');
	errors += check_strrchr("", 'a');
	errors += check_strrchr("a", 'a');
	errors += check_strrchr("abc", 'a' + 256);
	errors += check_strrchr("x\310y\310", 200);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_strrchr\n");
	else
		printf(RED "[KO]" RESET " ft_strrchr: %d errors\n", errors);
	return (errors);
}
