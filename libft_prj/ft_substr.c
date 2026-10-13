#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= (size_t)start || len == 0)
	{
		substr = malloc(1);
		substr[0] = '\0';
		return (substr);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
