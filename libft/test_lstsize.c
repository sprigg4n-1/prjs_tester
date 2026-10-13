/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:37:58 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/13 11:38:16 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
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

/* Builds a list of n nodes (content is NULL, only the count matters). */
static t_list	*make_list(int n)
{
	t_list	*list;

	list = NULL;
	while (n-- > 0)
		ft_lstadd_front(&list, ft_lstnew(NULL));
	return (list);
}

static int	check_size(int n)
{
	t_list	*list;
	t_list	*head;
	int		got;
	int		errors;

	errors = 0;
	list = make_list(n);
	head = list;
	got = ft_lstsize(list);
	if (got != n)
	{
		printf(RED "  KO" RESET " list of %d node(s): ft_lstsize returned "
			"%d\n", n, got);
		errors++;
	}
	if (list != head)
	{
		printf(RED "  KO" RESET " ft_lstsize changed the list pointer\n");
		errors++;
	}
	free_list(list);
	return (errors);
}

int	test_lstsize(void)
{
	int	errors;

	errors = 0;
	errors += check_size(0);
	errors += check_size(1);
	errors += check_size(2);
	errors += check_size(3);
	errors += check_size(10);
	errors += check_size(1000);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_lstsize\n");
	else
		printf(RED "[KO]" RESET " ft_lstsize: %d errors\n", errors);
	return (errors);
}
