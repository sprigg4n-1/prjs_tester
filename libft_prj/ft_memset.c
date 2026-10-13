#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*t_s;

	t_s = (char *)s;
	while (n--)
		*t_s++ = c;
	return (s);
}
