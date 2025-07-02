/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-08 00:00:00 by akuchmam          #+#    #+#             */
/*   Updated: 2025-01-08 00:00:00 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"

void	test_character(void)
{
	int ft_ret, std_ret;
	
	printf("=== TESTING CHARACTER (%%c) ===\n");
	
	printf("Test 1: Normal character 'A'\n");
	printf("ft_printf: ");
	fflush(stdout);
	ft_ret = ft_printf("Character: %c\n", 'A');
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("Character: %c\n", 'A');
    ft_ret == std_ret ? ft_printf(GREEN): ft_printf(RED);
	ft_printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	ft_printf(RESET);

	printf("Test 2: Null character\n");
	printf("ft_printf: ");
	fflush(stdout);
	ft_ret = ft_printf("Null char: '%c'\n", '\0');
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("Null char: '%c'\n", '\0');
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
	
	printf("Test 3: Multiple characters\n");
	printf("ft_printf: ");
	fflush(stdout);
	ft_ret = ft_printf("%c%c%c\n", 'H', 'i', '!');
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("%c%c%c\n", 'H', 'i', '!');
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
}

void	test_string(void)
{
	int ft_ret, std_ret;
	
	printf("=== TESTING STRING (%%s) ===\n");
	
	printf("Test 1: Normal string\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("String: %s\n", "Hello, World!");
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("String: %s\n", "Hello, World!");
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
	
	printf("Test 2: Empty string\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("Empty: '%s'\n", "");
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("Empty: '%s'\n", "");
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
	
	char * temp = NULL;
	printf("Test 3: NULL string\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("NULL: %s\n", (char *)NULL);
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("NULL: %s\n", temp);
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
	
	printf("Test 4: Multiple strings\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("%s %s %s\n", "Hello", "from", "ft_printf");
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("%s %s %s\n", "Hello", "from", "ft_printf");
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
}

void	test_pointer(void)
{
	int ft_ret, std_ret;
	int x = 42;
	char *str = "test";
	
	printf("=== TESTING POINTER (%%p) ===\n");
	
	printf("Test 1: Valid pointer\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("Pointer: %p\n", &x);
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("Pointer: %p\n", &x);
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
	
	printf("Test 2: String pointer\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("String ptr: %p\n", str);
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("String ptr: %p\n", str);
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
	
	printf("Test 3: NULL pointer\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("NULL ptr: %p\n", NULL);
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("NULL ptr: %p\n", NULL);
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
}

void	test_decimal(void)
{
	int ft_ret, std_ret;
	
	printf("=== TESTING DECIMAL (%%d and %%i) ===\n");
	
	printf("Test 1: Positive number\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("Positive: %d, %i\n", 42, 42);
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("Positive: %d, %i\n", 42, 42);
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
	
	printf("Test 2: Negative number\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("Negative: %d, %i\n", -42, -42);
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("Negative: %d, %i\n", -42, -42);
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
	
	printf("Test 3: Zero\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("Zero: %d, %i\n", 0, 0);
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("Zero: %d, %i\n", 0, 0);
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
	
	printf("Test 4: INT_MAX and INT_MIN\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("Max: %d, Min: %i\n", INT_MAX, INT_MIN);
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("Max: %d, Min: %i\n", INT_MAX, INT_MIN);
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
}

void	test_unsigned(void)
{
	int ft_ret, std_ret;
	
	printf("=== TESTING UNSIGNED (%%u) ===\n");
	
	printf("Test 1: Regular unsigned\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("Unsigned: %u\n", 42u);
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("Unsigned: %u\n", 42u);
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
	
	printf("Test 2: Zero\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("Zero: %u\n", 0u);
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("Zero: %u\n", 0u);
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
	
	printf("Test 3: UINT_MAX\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("Max: %u\n", UINT_MAX);
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("Max: %u\n", UINT_MAX);
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
}

void	test_hexadecimal(void)
{
	int ft_ret, std_ret;
	
	printf("=== TESTING HEXADECIMAL (%%x and %%X) ===\n");
	
	printf("Test 1: Regular hex\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("Hex: %x, %X\n", 255, 255);
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("Hex: %x, %X\n", 255, 255);
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
	
	printf("Test 2: Zero\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("Zero: %x, %X\n", 0, 0);
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("Zero: %x, %X\n", 0, 0);
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
	
	printf("Test 3: Large numbers\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("Large: %x, %X\n", 0xDEADBEEF, 0xDEADBEEF);
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("Large: %x, %X\n", 0xDEADBEEF, 0xDEADBEEF);
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
}

void	test_percent(void)
{
	int ft_ret, std_ret;
	
	printf("=== TESTING PERCENT (%%%%) ===\n");
	
	printf("Test 1: Single percent\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("Percent: %%\n");
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("Percent: %%\n");
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
	
	printf("Test 2: Multiple percents\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("Multiple: %% %% %%\n");
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("Multiple: %% %% %%\n");
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
	
	printf("Test 3: Mixed with other conversions\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("Mixed: %d%% complete\n", 50);
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("Mixed: %d%% complete\n", 50);
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
}

void	test_edge_cases(void)
{
	int ft_ret, std_ret;
	
	printf("=== TESTING EDGE CASES ===\n");
	
	printf("Test 1: Empty format string\n");
	printf("ft_printf: ");
	fflush(stdout);
	ft_ret = ft_printf("%s", "");
	printf("\nstd_printf: ");
	fflush(stdout);
	std_ret = printf("%s", "");
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("\nReturn values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
	
	printf("Test 2: Only text, no conversions\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("Just text, no conversions\n");
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("Just text, no conversions\n");
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
    
	printf("Test 3: NULL format string\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf(NULL);
    ft_ret == -1 ? printf(GREEN): printf(RED);
	printf("Return value: ft=%d (should be -1)\n\n", ft_ret);
	printf(RESET);

	printf("Test 4: Complex mixed format\n");
	printf("ft_printf:  ");
	fflush(stdout);
	ft_ret = ft_printf("Name: %s, Age: %d, ID: %x, Ptr: %p, Grade: %c\n",
		"John", 25, 0x1A2B, &ft_ret, 'A');
	printf("std_printf: ");
	fflush(stdout);
	std_ret = printf("Name: %s, Age: %d, ID: %x, Ptr: %p, Grade: %c\n",
		"John", 25, 0x1A2B, &std_ret, 'A');
    ft_ret == std_ret ? printf(GREEN): printf(RED);
	printf("Return values: ft=%d, std=%d\n\n", ft_ret, std_ret);
	printf(RESET);
}

int	main(void)
{
	printf("========================================\n");
	printf("         FT_PRINTF TEST SUITE          \n");
	printf("========================================\n\n");
	
	test_character();
	test_string();
	test_pointer();
	test_decimal();
	test_unsigned();
	test_hexadecimal();
	test_percent();
	test_edge_cases();
	
	printf("========================================\n");
	printf("            TESTS COMPLETED            \n");
	printf("========================================\n");
	
	return (0);
}
