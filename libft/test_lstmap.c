/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:07:06 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/13 13:08:28 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static int	g_f_calls;

/* f: returns a NEW uppercase copy of the string (old content untouched) */
static void	*upper_copy(void *content)
{
	char	*copy;
	size_t	i;

	g_f_calls++;
	copy = strdup(content);
	if (!copy)
		return (NULL);
	i = 0;
	while (copy[i])
	{
		if (copy[i] >= 'a' && copy[i] <= 'z')
			copy[i] -= 32;
		i++;
	}
	return (copy);
}

static void	del_free(void *content)
{
	free(content);
}

/* frees only the nodes, for the original list built from literals */
static void	free_nodes(t_list *lst)
{
	t_list	*next;

	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
}

static t_list	*make_list(const char **words, int n)
{
	t_list	*list;
	int		i;

	list = NULL;
	i = 0;
	while (i < n)
		ft_lstadd_back(&list, ft_lstnew((void *)words[i++]));
	return (list);
}

/* Compares a list with the expected strings, in order. */
static int	same_words(t_list *lst, const char **expected, int n)
{
	int	i;

	i = 0;
	while (i < n && lst && strcmp(lst->content, expected[i]) == 0)
	{
		lst = lst->next;
		i++;
	}
	return (i == n && lst == NULL);
}

static int	check_map(int n)
{
	const char	*words[] = {"apple", "banana", "cherry"};
	const char	*upper[] = {"APPLE", "BANANA", "CHERRY"};
	t_list		*old;
	t_list		*new;
	int			errors;

	errors = 0;
	old = make_list(words, n);
	g_f_calls = 0;
	new = ft_lstmap(old, upper_copy, del_free);
	if (g_f_calls != n)
	{
		printf(RED "  KO" RESET " list of %d: f called %d time(s)\n",
			n, g_f_calls);
		errors++;
	}
	if (!same_words(new, upper, n))
	{
		printf(RED "  KO" RESET " list of %d: new list has wrong content\n",
			n);
		errors++;
	}
	if (!same_words(old, words, n))
	{
		printf(RED "  KO" RESET " list of %d: old list was changed\n", n);
		errors++;
	}
	if (n > 0 && new == old)
	{
		printf(RED "  KO" RESET " list of %d: returned the old list, must "
			"build a new one\n", n);
		errors++;
	}
	ft_lstclear(&new, del_free);
	free_nodes(old);
	return (errors);
}

int	test_lstmap(void)
{
	int		errors;
	t_list	*old;

	errors = 0;
	errors += check_map(1);
	errors += check_map(2);
	errors += check_map(3);
	if (ft_lstmap(NULL, upper_copy, del_free) != NULL)
	{
		printf(RED "  KO" RESET " empty list must give NULL\n");
		errors++;
	}
	old = ft_lstnew("x");
	if (ft_lstmap(old, NULL, del_free) != NULL
		|| ft_lstmap(old, upper_copy, NULL) != NULL)
	{
		printf(RED "  KO" RESET " NULL f or del must give NULL\n");
		errors++;
	}
	free(old);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_lstmap\n");
	else
		printf(RED "[KO]" RESET " ft_lstmap: %d errors\n", errors);
	return (errors);
}
