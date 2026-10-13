#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length;
	size_t	length_src;
	size_t	i;

	length = 0;
	length_src = 0;
	while (length < size && dst[length])
		length++;
	while (src[length_src])
		length_src++;
	if (size == length)
		return (length_src + size);
	i = 0;
	while (length < size - 1 && src[i])
		dst[length++] = src[i++];
	dst[length] = '\0';
	return (length - i + length_src);
}
