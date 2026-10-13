#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_s;
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new_s = malloc(len + 1);
	if (!new_s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	new_s[len] = '\0';
	return (new_s);
}
