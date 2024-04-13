/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:49:10 by jedusser          #+#    #+#             */
/*   Updated: 2023/12/01 12:12:39 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	int		i;
	int		str_len;
	char	needle;

	needle = searchedChar;
	str_len = ft_strlen(string);
	i = str_len;
	while (i >= 0)
	{
		if (string[i] == needle)
			return ((char *)&string[i]);
		if (needle == '\0')
			return ((char *)&string[str_len]);
		else
			i--;
	}
	return (NULL);
}
