#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*c_dest;
	char	*c_src;

	c_dest = (char *)dest;
	c_src = (char *)src;
	if (!dest && !src)
		return (0);
	if (dest <= src)
	{
		while (n--)
			*c_dest++ = *c_src++;
	}
	else if (dest > src)
	{
		c_dest += n - 1;
		c_src += n - 1;
		while (n--)
			*c_dest-- = *c_src--;
	}
	return (dest);
}
