/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:27:37 by jedusser          #+#    #+#             */
/*   Updated: 2024/01/11 15:32:03 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_up(unsigned long long nb)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_print_hex_up(nb / 16);
		count += ft_print_hex_up(nb % 16);
	}
	else
	{
		if (nb < 10)
			count += ft_print_char(nb + '0');
		else
			count += ft_print_char(nb - 10 + 'A');
	}
	return (count);
}
