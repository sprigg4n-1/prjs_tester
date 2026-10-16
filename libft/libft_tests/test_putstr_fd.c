#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"
#define BUF_SIZE 8192

static int	check_putstr(char *s, int line)
{
	int		fds[2];
	char	buf[BUF_SIZE];
	ssize_t	n;
	size_t	total;

	if (pipe(fds) == -1)
		return (1);
	ft_putstr_fd(s, fds[1]);
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
	if (total != strlen(s) || memcmp(buf, s, total) != 0)
	{
		printf(RED "  KO" RESET " test on line %d: wrote %zu byte(s) \"%s\", "
			"expected %zu byte(s) \"%s\"\n", line, total, buf, strlen(s), s);
		return (1);
	}
	return (0);
}

int	test_putstr_fd(void)
{
	int		errors;
	char	big[4001];

	errors = 0;
	errors += check_putstr("Hello", __LINE__);
	errors += check_putstr("Hello, World!", __LINE__);
	errors += check_putstr("a", __LINE__);
	errors += check_putstr("", __LINE__);
	errors += check_putstr("line1\nline2\n", __LINE__);
	errors += check_putstr("tab\there", __LINE__);
	errors += check_putstr("\200\377", __LINE__);
	memset(big, 'q', 4000);
	big[4000] = '\0';
	errors += check_putstr(big, __LINE__);
	ft_putstr_fd(NULL, 1);
	ft_putstr_fd("x", -1);
	if (errors == 0)
		printf(GREEN "[OK]" RESET " ft_putstr_fd\n");
	else
		printf(RED "[KO]" RESET " ft_putstr_fd: %d errors\n", errors);
	return (errors);
}
