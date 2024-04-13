/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:49:42 by jedusser          #+#    #+#             */
/*   Updated: 2023/12/06 15:58:57 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*src;
	size_t				i;

	dst = (unsigned char *)destination;
	src = (const unsigned char *)source;
	if (destination == NULL && source == NULL)
		return (NULL);
	if (destination <= source || dst >= (src + n))
	{
		i = 0;
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- != 0)
			dst[i] = src[i];
	}
	return (destination);
}
