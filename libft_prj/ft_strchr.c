/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romankovinia <romankovinia@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 14:49:23 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 21:35:06 by romankovini      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*c_s;
	char	c_h;
	int		len;

	len = 0;
	c_h = (char)c;
	c_s = (char *)s;
	while (c_s[len])
		len++;
	while (len-- >= 0)
	{
		if (*c_s == c_h)
			return (c_s);
		c_s++;
	}
	return (0);
}
