/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:32:12 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/12 17:34:25 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == '\0' || *(s + 1) == c))
			count++;
		s++;
	}
	return (count);
}

static int	add_word(char **arr, size_t pos, const char *start, size_t len)
{
	arr[pos] = ft_substr(start, 0, len);
	if (arr[pos])
		return (1);
	while (pos > 0)
	{
		free(arr[pos - 1]);
		pos--;
	}
	free(arr);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	str_arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !str_arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!add_word(str_arr, j, &s[i], word_len(&s[i], c)))
				return (NULL);
			i = i + word_len(&s[i], c);
			j++;
		}
		else
			i++;
	}
	str_arr[j] = NULL;
	return (str_arr);
}
