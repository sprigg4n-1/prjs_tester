/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:30:43 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/13 12:36:03 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static int	g_del_calls;
static void	*g_del_arg;

/* del for heap strings: frees them and remembers what it got */
static void	del_free(void *content)
{
	g_del_calls++;
	g_del_arg = content;
	free(content);
}

/* del for content that must not be freed (e.g. string literals) */
static void	del_nothing(void *content)
{
	g_del_calls++;
	g_del_arg = content;
}

static int	check_del_called_once(void)
{
	t_list	*node;
	char	*str;
	int		errors;

	errors = 0;
	str = strdup("on the heap");
	node = ft_lstnew(str);
	g_del_calls = 0;
	g_del_arg = NULL;
	ft_lstdelone(node, del_free);
	if (g_del_calls != 1)
	{
		printf(RED "  KO" RESET " del called %d times, expected 1\n",
			g_del_calls);
		errors++;
	}
	if (g_del_arg != str)
	{
		printf(RED "  KO" RESET " del got the wrong pointer, expected the "
			"node's content\n");
		errors++;
	}
	return (errors);
}

static int	check_next_untouched(void)
{
	t_list	*a;
	t_list	*b;
	int		errors;

	errors = 0;
	a = ft_lstnew("A");
	b = ft_lstnew("B");
	a->next = b;
	g_del_calls = 0;
	ft_lstdelone(a, del_nothing);
	if (g_del_calls != 1)
	{
		printf(RED "  KO" RESET " deleting one node called del %d times, "
			"next node must not be touched\n", g_del_calls);
		errors++;
	}
	if (strcmp(b->content, "B") != 0 || b->next != NULL)
	{
		printf(RED "  KO" RESET " next node was changed\n");
		errors++;
	}
	free(b);
	return (errors);
}

int	test_lstdelone(void)
{
	int		errors;
	t_list	*node;

	errors = 0;
	errors += check_del_called_once();
	errors += check_next_untouched();
	node = ft_lstnew("literal");
	ft_lstdelone(node, del_nothing);
	ft_lstdelone(NULL, del_free);
	node = ft_lstnew(NULL);
	ft_lstdelone(node, NULL);
	free(node);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_lstdelone\n");
	else
		printf(RED "[KO]" RESET " ft_lstdelone: %d errors\n", errors);
	return (errors);
}
