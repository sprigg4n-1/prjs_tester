#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"
#define BUF_SIZE 8192

static int	check_putendl(char *s, int line)
{
	int		fds[2];
	char	buf[BUF_SIZE];
	ssize_t	n;
	size_t	total;
	size_t	len;

	if (pipe(fds) == -1)
		return (1);
	ft_putendl_fd(s, fds[1]);
	close(fds[1]);
	total = 0;
	n = read(fds[0], buf, BUF_SIZE - 1);
	while (n > 0)
	{
		total += n;
		n = read(fds[0], buf + total, BUF_SIZE - 1 - total);
	}
	close(fds[0]);
	buf[total] = '\0';
	len = strlen(s);
	if (total != len + 1 || memcmp(buf, s, len) != 0 || buf[len] != '\n')
	{
		printf(RED "  KO" RESET " test on line %d: wrote %zu byte(s) \"%s\", "
			"expected %zu byte(s) \"%s\\n\"\n", line, total, buf, len + 1, s);
		return (1);
	}
	return (0);
}

int	test_putendl_fd(void)
{
	int		errors;
	char	big[4001];

	errors = 0;
	errors += check_putendl("Hello", __LINE__);
	errors += check_putendl("Hello, World!", __LINE__);
	errors += check_putendl("a", __LINE__);
	errors += check_putendl("", __LINE__);
	errors += check_putendl("already\n", __LINE__);
	errors += check_putendl("tab\there", __LINE__);
	errors += check_putendl("\200\377", __LINE__);
	memset(big, 'q', 4000);
	big[4000] = '\0';
	errors += check_putendl(big, __LINE__);
	ft_putendl_fd(NULL, 1);
	ft_putendl_fd("x", -1);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_putendl_fd\n");
	else
		printf(RED "[KO]" RESET " ft_putendl_fd: %d errors\n", errors);
	return (errors);
}
