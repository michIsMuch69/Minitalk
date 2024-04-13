/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:29:00 by jedusser          #+#    #+#             */
/*   Updated: 2024/01/11 15:32:03 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>

int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_hex_up(unsigned long long nb);
int	ft_print_hex_low(unsigned long long nb);
int	ft_print_decimal(int nb);
int	ft_print_pointer(unsigned long long ptr);
int	ft_print_unsigned_dec(unsigned int nb);
int	ft_printf(const char *format, ...);

#endif