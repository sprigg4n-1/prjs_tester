/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:08:57 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 12:11:00 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 < *s2 || !*s1)
			return (*s1 - *s2);
		if (*s2 < *s1 || !*s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
