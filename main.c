/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 11:26:08 by rkovinia          #+#    #+#             */
/*   Updated: 2026/10/09 16:41:20 by rkovinia         ###   ########.fr       */
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
int	test_strchr(void);
int	test_strrchr(void);
int	test_strncmp(void);
int	test_memchr(void);
int	test_memcmp(void);
int	test_strnstr(void);
int	test_atoi(void);
int	test_calloc(void);
int test_strdup(void);

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
	errors += test_strchr();
	errors += test_strrchr();
	errors += test_strncmp();
	errors += test_memchr();
	errors += test_memcmp();
	errors += test_strnstr();
	errors += test_atoi();
	errors += test_calloc();
	errors += test_strdup();
	return (errors != 0);
}
