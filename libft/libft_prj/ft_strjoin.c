/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 12:27:17 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/12 12:36:23 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*conc_str;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	conc_str = malloc(len + 1);
	if (!conc_str)
		return (NULL);
	ft_strlcpy(conc_str, s1, ft_strlen(s1) + 1);
	ft_strlcat(conc_str, s2, len + 1);
	return (conc_str);
}
