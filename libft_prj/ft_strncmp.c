/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:08:57 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 16:47:56 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s_s1;
	unsigned char	*s_s2;

	s_s1 = (unsigned char *)s1;
	s_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (*s_s1 < *s_s2 || !*s_s1)
			return (*s_s1 - *s_s2);
		if (*s_s2 < *s_s1 || !*s_s2)
			return (*s_s1 - *s_s2);
		s_s1++;
		s_s2++;
	}
	return (0);
}
