/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:01:45 by dusserrejea       #+#    #+#             */
/*   Updated: 2023/11/21 15:42:06 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbdelement, size_t tailleelement)
{
	void	*ptr;

	ptr = malloc (tailleelement * nbdelement);
	if (ptr == NULL)
		return (NULL);
	if (nbdelement == 0)
		((char *)ptr)[0] = '\0';
	else
		ft_bzero(ptr, tailleelement * nbdelement);
	return (ptr);
}
