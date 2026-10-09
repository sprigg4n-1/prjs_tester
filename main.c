/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 11:26:08 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 16:15:47 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	test_isalpha(void);
int	test_isdigit(void);
int	test_isalnum(void);
int	test_isascii(void);
int	test_isprint(void);
int	test_tolower(void);
int	test_toupper(void);
int	test_strlen(void);
int	test_memset(void);
int	test_bzero(void);
int	test_memcpy(void);
int	test_memmove(void);
int	test_strlcpy(void);
int	test_strlcat(void);

int	main(void)
{
	int	errors;

	errors = 0;
	errors += test_isalpha();
	errors += test_isdigit();
	errors += test_isalnum();
	errors += test_isascii();
	errors += test_isprint();
	errors += test_tolower();
	errors += test_toupper();
	errors += test_strlen();
	errors += test_memset();
	errors += test_bzero();
	errors += test_memcpy();
	errors += test_memmove();
	errors += test_strlcpy();
	errors += test_strlcat();
	return (errors != 0);
}
