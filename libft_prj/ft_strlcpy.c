#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	length;

	length = 0;
	if (size == 0)
	{
		while (src[length])
			length++;
		return (length);
	}
	while (length < size - 1 && src[length])
	{
		dst[length] = src[length];
		length++;
	}
	dst[length] = '\0';
	while (src[length])
		length++;
	return (length);
}
