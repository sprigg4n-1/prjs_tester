/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:07:56 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/13 11:08:39 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static int	check_lstnew(void *content, const char *label)
{
	t_list	*node;
	int		errors;

	errors = 0;
	node = ft_lstnew(content);
	if (!node)
	{
		printf(RED "  KO" RESET " lstnew(%s): returned NULL\n", label);
		return (1);
	}
	if (node->content != content)
	{
		printf(RED "  KO" RESET " lstnew(%s): content is not the same "
			"pointer that was passed\n", label);
		errors++;
	}
	if (node->next != NULL)
	{
		printf(RED "  KO" RESET " lstnew(%s): next is not NULL\n", label);
		errors++;
	}
	free(node);
	return (errors);
}

static int	check_two_nodes(void)
{
	t_list	*a;
	t_list	*b;
	int		errors;

	errors = 0;
	a = ft_lstnew("first");
	b = ft_lstnew("second");
	if (!a || !b || a == b)
	{
		printf(RED "  KO" RESET " two lstnew calls must return two "
			"different nodes\n");
		errors = 1;
	}
	free(a);
	free(b);
	return (errors);
}

int	test_lstnew(void)
{
	int		errors;
	int		number;
	char	*heap_str;

	errors = 0;
	number = 42;
	heap_str = strdup("on the heap");
	errors += check_lstnew("Hello", "\"Hello\"");
	errors += check_lstnew("", "\"\"");
	errors += check_lstnew(NULL, "NULL");
	errors += check_lstnew(&number, "&number");
	errors += check_lstnew(heap_str, "heap string");
	errors += check_two_nodes();
	free(heap_str);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_lstnew\n");
	else
		printf(RED "[KO]" RESET " ft_lstnew: %d errors\n", errors);
	return (errors);
}
