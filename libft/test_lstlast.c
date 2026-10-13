/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:44:28 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/13 12:11:56 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static void	free_list(t_list *lst)
{
	t_list	*next;

	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
}

/* Builds a list from words, in the same order as the array. */
static t_list	*make_list(const char **words, int n)
{
	t_list	*list;

	list = NULL;
	while (n-- > 0)
		ft_lstadd_front(&list, ft_lstnew((void *)words[n]));
	return (list);
}

static int	check_last(const char **words, int n)
{
	t_list	*list;
	t_list	*got;
	int		errors;

	errors = 0;
	list = make_list(words, n);
	got = ft_lstlast(list);
	if (!got)
	{
		printf(RED "  KO" RESET " list of %d node(s): returned NULL\n", n);
		errors++;
	}
	else if (got->next != NULL || got->content != words[n - 1])
	{
		printf(RED "  KO" RESET " list of %d node(s): expected \"%s\", "
			"got \"%s\"\n", n, words[n - 1], (char *)got->content);
		errors++;
	}
	free_list(list);
	return (errors);
}

int	test_lstlast(void)
{
	int			errors;
	const char	*words[] = {"one", "two", "three", "four", "five"};

	errors = 0;
	if (ft_lstlast(NULL) != NULL)
	{
		printf(RED "  KO" RESET " empty list: expected NULL\n");
		errors++;
	}
	errors += check_last(words, 1);
	errors += check_last(words, 2);
	errors += check_last(words, 3);
	errors += check_last(words, 5);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_lstlast\n");
	else
		printf(RED "[KO]" RESET " ft_lstlast: %d errors\n", errors);
	return (errors);
}
