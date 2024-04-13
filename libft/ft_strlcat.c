/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:30:01 by jedusser          #+#    #+#             */
/*   Updated: 2023/12/06 16:00:45 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *destination, const char *source, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	src_len = 0;
	dst_len = 0;
	while (destination[dst_len])
		dst_len++;
	while (source[src_len])
		src_len++;
	if (size == 0)
		return (size + src_len);
	if (dst_len >= size)
		return (size + src_len);
	while (source[i] && i < size - dst_len - 1)
	{
		destination[dst_len + i] = source[i];
		i++;
	}
	destination[dst_len + i] = '\0';
	return (dst_len + src_len);
}
