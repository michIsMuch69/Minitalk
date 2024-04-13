/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:22:25 by jedusser          #+#    #+#             */
/*   Updated: 2023/12/01 12:11:45 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	unsigned char		*dst;
	unsigned char		*src;

	dst = (unsigned char *)destination;
	src = (unsigned char *)source;
	if (dst == (void *)0 && src == (void *)0)
		return (destination);
	dst = (unsigned char *)destination;
	src = (unsigned char *)source;
	while (n > 0)
	{
		*dst = *src;
		dst++;
		src++;
		n--;
	}
	return (destination);
}
