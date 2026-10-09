/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 12:50:56 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 16:50:13 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dupl;
	size_t	i;
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	dupl = malloc(len + 1);
	if (!dupl)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dupl[i] = s[i];
		i++;
	}
	dupl[i] = '\0';
	return (dupl);
}
