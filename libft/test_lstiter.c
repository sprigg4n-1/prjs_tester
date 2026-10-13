/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:51:19 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/13 12:51:43 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static int	g_calls;
static char	g_seen[64];

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
static t_list	*make_list(char **words, int n)
{
	t_list	*list;
	int		i;

	list = NULL;
	i = 0;
	while (i < n)
		ft_lstadd_back(&list, ft_lstnew(words[i++]));
	return (list);
}

/* f that records the first letter of each content it receives */
static void	record(void *content)
{
	g_seen[g_calls] = ((char *)content)[0];
	g_calls++;
	g_seen[g_calls] = '\0';
}

/* f that changes the content in place */
static void	to_upper(void *content)
{
	char	*s;

	s = content;
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s -= 32;
		s++;
	}
}

static int	check_order(int n, const char *expected)
{
	char	w1[] = "apple";
	char	w2[] = "banana";
	char	w3[] = "cherry";
	char	*words[3];
	t_list	*list;

	words[0] = w1;
	words[1] = w2;
	words[2] = w3;
	list = make_list(words, n);
	g_calls = 0;
	g_seen[0] = '\0';
	ft_lstiter(list, record);
	free_list(list);
	if (g_calls != n || strcmp(g_seen, expected) != 0)
	{
		printf(RED "  KO" RESET " list of %d node(s): f called %d time(s) "
			"in order \"%s\", expected %d in order \"%s\"\n",
			n, g_calls, g_seen, n, expected);
		return (1);
	}
	return (0);
}

static int	check_modify(void)
{
	char	w1[] = "hello";
	char	w2[] = "world";
	char	*words[2];
	t_list	*list;
	int		errors;

	words[0] = w1;
	words[1] = w2;
	list = make_list(words, 2);
	ft_lstiter(list, to_upper);
	errors = 0;
	if (strcmp(w1, "HELLO") != 0 || strcmp(w2, "WORLD") != 0)
	{
		printf(RED "  KO" RESET " f did not change the content: got \"%s\", "
			"\"%s\"\n", w1, w2);
		errors = 1;
	}
	free_list(list);
	return (errors);
}

int	test_lstiter(void)
{
	int	errors;

	errors = 0;
	errors += check_order(0, "");
	errors += check_order(1, "a");
	errors += check_order(2, "ab");
	errors += check_order(3, "abc");
	errors += check_modify();
	ft_lstiter(NULL, record);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_lstiter\n");
	else
		printf(RED "[KO]" RESET " ft_lstiter: %d errors\n", errors);
	return (errors);
}
