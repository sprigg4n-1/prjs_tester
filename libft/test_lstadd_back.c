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

static int	check_list(t_list *lst, const char **expected, const char *label)
{
	size_t	i;

	i = 0;
	while (expected[i] && lst && strcmp(lst->content, expected[i]) == 0)
	{
		lst = lst->next;
		i++;
	}
	if (expected[i] || lst)
	{
		printf(RED "  KO" RESET " %s: list differs at position %zu\n",
			label, i);
		return (1);
	}
	return (0);
}

static int	check_empty_list(void)
{
	t_list		*list;
	t_list		*node;
	const char	*exp[] = {"A", NULL};
	int			errors;

	errors = 0;
	list = NULL;
	node = ft_lstnew("A");
	ft_lstadd_back(&list, node);
	if (list != node)
	{
		printf(RED "  KO" RESET " empty list: head must become the new "
			"node\n");
		errors++;
	}
	errors += check_list(list, exp, "empty list");
	free_list(list);
	return (errors);
}

static int	check_order(void)
{
	t_list		*list;
	t_list		*head;
	const char	*exp[] = {"A", "B", "C", "D", NULL};
	int			errors;

	errors = 0;
	list = NULL;
	ft_lstadd_back(&list, ft_lstnew("A"));
	head = list;
	ft_lstadd_back(&list, ft_lstnew("B"));
	ft_lstadd_back(&list, ft_lstnew("C"));
	ft_lstadd_back(&list, ft_lstnew("D"));
	if (list != head)
	{
		printf(RED "  KO" RESET " head changed after adding to the back\n");
		errors++;
	}
	errors += check_list(list, exp, "add A, B, C, D to back");
	free_list(list);
	return (errors);
}

static int	check_null_args(void)
{
	t_list		*list;
	const char	*exp[] = {"A", NULL};
	int			errors;

	list = ft_lstnew("A");
	ft_lstadd_back(&list, NULL);
	errors = check_list(list, exp, "add NULL node");
	ft_lstadd_back(NULL, NULL);
	free_list(list);
	return (errors);
}

int	test_lstadd_back(void)
{
	int	errors;

	errors = 0;
	errors += check_empty_list();
	errors += check_order();
	errors += check_null_args();
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_lstadd_back\n");
	else
		printf(RED "[KO]" RESET " ft_lstadd_back: %d errors\n", errors);
	return (errors);
}
