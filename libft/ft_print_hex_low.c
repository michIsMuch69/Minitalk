/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_low.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:13:46 by jedusser          #+#    #+#             */
/*   Updated: 2024/01/11 15:47:09 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_low(unsigned long long nb)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_print_hex_low(nb / 16);
		count += ft_print_hex_low(nb % 16);
	}
	else
	{
		if (nb < 10)
			count += ft_print_char(nb + '0');
		else
			count += ft_print_char(nb - 10 + 'a');
	}
	return (count);
}
