/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 11:06:41 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 12:11:00 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
