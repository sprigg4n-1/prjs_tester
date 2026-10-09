/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 14:55:04 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/08 11:49:50 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*last_char;

	last_char = 0;
	while (*s)
	{
		if (*s == c)
			last_char = (char *)s;
		s++;
	}
	return (last_char);
}
