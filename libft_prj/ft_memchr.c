#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*c_s;

	c_s = (unsigned char *)s;
	while (n--)
	{
		if (*c_s == (unsigned char)c)
			return (c_s);
		c_s++;
	}
	return (0);
}
