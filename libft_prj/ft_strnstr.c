#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (len > i && big[i])
	{
		j = 0;
		while (len > i && little[j] && big[i] && little[j] == big[i])
		{
			j++;
			i++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i - j]);
		i = i - j + 1;
	}
	return (0);
}
