/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romankovinia <romankovinia@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 14:55:04 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 21:35:51 by romankovini      ###   ########.fr       */
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
