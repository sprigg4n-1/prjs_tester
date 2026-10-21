/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 23:35:27 by romankovini       #+#    #+#             */
/*   Updated: 2026/10/21 14:16:52 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_print_chars(va_list *ptr, char c);
int	ft_print_numbs(va_list *ptr, char c);
int	ft_print_hex(va_list *ptr, char c);

int	ft_base_convertor(unsigned long nbr, int base_len, char *base);

#endif
