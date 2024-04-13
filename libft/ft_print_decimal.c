/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:27:27 by jedusser          #+#    #+#             */
/*   Updated: 2024/01/11 15:32:03 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		count += ft_print_char('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		count += ft_print_decimal(nb / 10);
		count += ft_print_char(nb % 10 + '0');
	}
	else
	{
		count += ft_print_char(nb + '0');
	}
	return (count);
}
