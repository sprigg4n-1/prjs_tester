#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static int	g_del_calls;

static void	del_free(void *content)
{
	g_del_calls++;
	free(content);
}

static t_list	*make_list(int n)
{
	t_list	*list;

	list = NULL;
	while (n-- > 0)
		ft_lstadd_back(&list, ft_lstnew(strdup("node")));
	return (list);
}

static int	check_clear(int n)
{
	t_list	*list;
	int		errors;

	errors = 0;
	list = make_list(n);
	g_del_calls = 0;
	ft_lstclear(&list, del_free);
	if (g_del_calls != n)
	{
		printf(RED "  KO" RESET " list of %d node(s): del called %d "
			"time(s), expected %d\n", n, g_del_calls, n);
		errors++;
	}
	if (list != NULL)
	{
		printf(RED "  KO" RESET " list of %d node(s): list pointer is not "
			"NULL after clear\n", n);
		errors++;
	}
	return (errors);
}

int	test_lstclear(void)
{
	int		errors;
	t_list	*list;

	errors = 0;
	errors += check_clear(0);
	errors += check_clear(1);
	errors += check_clear(2);
	errors += check_clear(5);
	errors += check_clear(1000);
	ft_lstclear(NULL, del_free);
	list = make_list(1);
	ft_lstclear(&list, NULL);
	if (list)
	{
		free(list->content);
		free(list);
	}
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_lstclear\n");
	else
		printf(RED "[KO]" RESET " ft_lstclear: %d errors\n", errors);
	return (errors);
}
