/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:28:16 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/13 14:48:34 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

int handle_format_specifier(char formatSpecifier, va_list args)
{
	if (formatSpecifier == '%')
		return (ft_print_char('%'));
	else if (formatSpecifier == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (formatSpecifier == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (formatSpecifier == 'p')
		return (ft_print_pointer(va_arg(args, unsigned long long)));
	else if (formatSpecifier == 'd' || formatSpecifier == 'i')
		return (ft_print_decimal(va_arg(args, int)));
	else if (formatSpecifier == 'u')
		return (ft_print_unsigned_dec(va_arg(args, unsigned int)));
	else if (formatSpecifier == 'x')
		return (ft_print_hex_low(va_arg(args, unsigned int)));
	else if (formatSpecifier == 'X')
		return (ft_print_hex_up(va_arg(args, unsigned int)));
	return (0);
}

int	handle_format_string(char const *format, va_list args)
{
	int	index;
	int	total;

	total = 0;
	index = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			index++;
			total += handle_format_specifier(format[index], args);
		}
		else
		{
			total += ft_print_char(format[index]);
		}
		index++;
	}
	return (total);
}

int	ft_printf(const char *format, ...)
{
	int		total;
	va_list	args;

	total = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	total = handle_format_string(format, args);
	va_end(args);
	return (total);
}

/* Note : ici, il est possible de stocker la valeur contenue dans le &c de mon ft_putchar dans un type int, 
puisqu'il s'agit bien de sa valeur ascii ! */
// int    main()
// {
//     int    i;
//     i = 0;
//     ft_printf("Hello World\n");
//     ft_printf("There is 10 : %d \n", 10);
//     ft_printf("There is 10 and 30 : %d %d\n", 10, 30);
//     ft_printf("char Z : %c\n10 : %d\nchar M : %c\n", 'Z', 10, 'M');
//     ft_printf("str : %s\n","bonjour");
//     i = ft_printf("-500 en hexa : %x\n", 0);
//     ft_printf("ret : %d\n", i);
//     ft_printf("100 : %u\n", 100);
//     ft_printf("-100 : %u\n", -100);
//     i = ft_printf("address : %p\n", (void *)-9223372036854775808);
//     printf("ret : %d\n", i);
//     ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
//     ft_printf(" %c \n", '0');
//     ft_printf(" NULL %s NULL \n", NULL);


//     printf("Hello World\n");
//     printf("There is 10 : %d \n", 10);
//     printf("There is 10 and 30 : %d %d\n", 10, 30);
//     printf("char Z : %c\n10 : %d\nchar M : %c\n", 'Z', 10, 'M');
//     printf("str : %s\n","bonjour");
//     i = printf("-500 en hexa : %x\n", 0);
//     printf("ret : %d\n", i);
//     printf("100 : %u\n", 100);
//     printf("-100 : %u\n", -100);
//     i = printf("address : %p\n", (void *)-9223372036854775808);
//     printf("ret : %d\n", i);
//     printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
//     printf(" %c \n", '0');
//     printf(" NULL %s NULL \n", (char *)NULL);
//     (void)i;
// }


// int main()
// {
// 	int val1;
// 	int val2;
//     int val = 42;
//     int *pointer = &val;
// 	val1 = printf   (NULL);
//     val2 = ft_printf(NULL);       

// 	printf("val1 = %d\n val2 = %d\n", val1, val2);
// }  