/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 10:35:13 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/13 10:40:34 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nl;
	char	c;

	nl = (long)n;
	if (nl < 0)
	{
		write(fd, "-", 1);
		nl *= -1;
	}
	if (nl > 9)
		ft_putnbr_fd(nl / 10, fd);
	c = nl % 10 + 48;
	write(fd, &c, 1);
}
