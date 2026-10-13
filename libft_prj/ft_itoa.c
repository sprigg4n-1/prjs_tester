/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:08:56 by romankovini       #+#    #+#             */
/*   Updated: 2026/10/12 17:12:27 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	numlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*numb;
	long	ln;
	size_t	len;

	ln = (long)n;
	len = numlen(ln);
	numb = (char *)malloc(len + 1);
	if (!numb)
		return (NULL);
	numb[len] = '\0';
	if (ln < 0)
	{
		numb[0] = '-';
		ln = -ln;
	}
	if (ln == 0)
		numb[0] = '0';
	while (ln > 0)
	{
		numb[--len] = (ln % 10) + '0';
		ln /= 10;
	}
	return (numb);
}
