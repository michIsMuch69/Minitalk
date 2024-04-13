/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:51:48 by jedusser          #+#    #+#             */
/*   Updated: 2023/12/05 10:16:24 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	unsigned char	*ptr;
	unsigned char	needle;
	size_t			i;

	i = 0;
	needle = (unsigned char)searchedChar;
	ptr = (unsigned char *)memoryBlock;
	while (i < size)
	{
		if (ptr[i] == needle)
			return ((char *) &ptr[i]);
		else
			i++;
	}
	return (NULL);
}
