/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:27:52 by jedusser          #+#    #+#             */
/*   Updated: 2024/01/11 15:27:56 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(unsigned long long ptr)
{
	int	count;

	if (!ptr)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	count = 0;
	count += ft_print_str("0x");
	count += ft_print_hex_low(ptr);
	return (count);
}
