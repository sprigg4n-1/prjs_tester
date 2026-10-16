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
	const char	*exp[] = {"X", NULL};
	int			errors;

	errors = 0;
	list = NULL;
	node = ft_lstnew("X");
	ft_lstadd_front(&list, node);
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
	t_list		*old_head;
	const char	*exp[] = {"C", "B", "A", NULL};
	int			errors;

	errors = 0;
	list = ft_lstnew("A");
	old_head = list;
	ft_lstadd_front(&list, ft_lstnew("B"));
	if (list->next != old_head)
	{
		printf(RED "  KO" RESET " new node must point to the old head\n");
		errors++;
	}
	ft_lstadd_front(&list, ft_lstnew("C"));
	errors += check_list(list, exp, "add A, B, C to front");
	free_list(list);
	return (errors);
}

static int	check_null_args(void)
{
	t_list		*list;
	const char	*exp[] = {"A", NULL};
	int			errors;

	list = ft_lstnew("A");
	ft_lstadd_front(&list, NULL);
	errors = check_list(list, exp, "add NULL node");
	ft_lstadd_front(NULL, NULL);
	free_list(list);
	return (errors);
}

int	test_lstadd_front(void)
{
	int	errors;

	errors = 0;
	errors += check_empty_list();
	errors += check_order();
	errors += check_null_args();
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_lstadd_front\n");
	else
		printf(RED "[KO]" RESET " ft_lstadd_front: %d errors\n", errors);
	return (errors);
}
