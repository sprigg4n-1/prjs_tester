/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 12:50:56 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 14:50:11 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dupl;
	size_t	i;

	dupl = malloc(ft_strlen(s) + 1);
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
