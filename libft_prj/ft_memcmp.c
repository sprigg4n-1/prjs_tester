/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:31:27 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 12:11:22 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*c_s1;
	char	*c_s2;

	c_s1 = (char *)s1;
	c_s2 = (char *)s2;
	while (n--)
	{
		if (*c_s1 < *c_s2)
			return (*c_s1 - *c_s2);
		if (*c_s2 < *c_s1)
			return (*c_s1 - *c_s2);
		c_s1++;
		c_s2++;
	}
	return (0);
}
