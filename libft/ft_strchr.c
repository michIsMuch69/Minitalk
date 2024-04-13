/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:10:58 by jedusser          #+#    #+#             */
/*   Updated: 2023/12/01 12:12:08 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	int		i;
	int		str_len;
	char	needle;

	needle = searchedChar;
	str_len = ft_strlen(string);
	i = 0;
	while (i <= str_len)
	{
		if (string[i] == needle)
			return ((char *)&string[i]);
		if (needle == '\0')
			return ((char *)&string[str_len]);
		else
			i++;
	}
	return (NULL);
}
