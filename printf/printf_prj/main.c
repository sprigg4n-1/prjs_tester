/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romankovinia <romankovinia@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:32:03 by romankovini       #+#    #+#             */
/*   Updated: 2026/10/19 13:46:17 by romankovini      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	sum(int count, ...)
{

}

int	main(void)
{
	int	count;

	count = 8;
	printf("%%d: %d\n", 42);
	printf("%%c: %c\n", 'A');
	printf("%%s: %s\n", "Hello, World!");
	printf("%%p: %p\n", &count);
	printf("%%i: %i\n", 0x2a);
	printf("%%u: %u\n", -1);
	printf("%%x: %x\n", 42);
	printf("%%X: %X\n", 42);
	return (0);
}