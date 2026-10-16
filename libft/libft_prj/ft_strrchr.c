/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 14:55:04 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/12 11:32:33 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*last_char;
	char	c_h;
	int		len;

	len = 0;
	c_h = (char)c;
	last_char = 0;
	while (s[len])
		len++;
	while (len-- >= 0)
	{
		if (*s == c_h)
			last_char = (char *)s;
		s++;
	}
	return (last_char);
}
