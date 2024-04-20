/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:30:19 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/20 15:17:05 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *src, size_t size, size_t src_size)
{
	void	*new_buffer;
	
	new_buffer = NULL;
	new_buffer = ft_calloc(size, sizeof(char));
	if (!new_buffer)			
		return (NULL);
	new_buffer = ft_memcpy(new_buffer, src, src_size);
	free(src);
	return (new_buffer);
}


