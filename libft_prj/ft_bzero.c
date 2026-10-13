#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*c_s;

	c_s = (char *)s;
	while (n--)
		*c_s++ = '\0';
}
