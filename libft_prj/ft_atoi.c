/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 16:48:20 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 12:11:08 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	calc_num(const char *nptr, int is_neg)
{
	int	numb;

	numb = 0;
	while (*nptr >= 48 && *nptr <= 57)
	{
		numb = numb * 10 + (*nptr - 48);
		nptr++;
	}
	return (numb * is_neg);
}

static	void	check_symbol(char c, int *count_sp_sb, int *is_neg)
{
	if (c == '-')
		*is_neg *= -1;
	*count_sp_sb += 1;
}

int	ft_atoi(const char *nptr)
{
	int	is_neg;
	int	count_sp_sb;

	count_sp_sb = 0;
	is_neg = 1;
	while (*nptr && count_sp_sb <= 1)
	{
		if (*nptr == 32 || (*nptr >= 7 && *nptr <= 13))
		{
			nptr++;
			continue ;
		}
		else if ((*nptr == '-' || *nptr == '+') && *(nptr + 1) != 32)
			check_symbol(*nptr, &count_sp_sb, &is_neg);
		else if (*nptr >= 48 && *nptr <= 57)
			return (calc_num(nptr, is_neg));
		else
			break ;
		nptr++;
	}
	return (0);
}
