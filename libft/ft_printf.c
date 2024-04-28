/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:28:16 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/28 13:13:03 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format_specifier(char formatSpecifier, va_list args)
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
