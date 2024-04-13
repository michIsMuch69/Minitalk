/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:46:30 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/19 13:41:44 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	slen(char const *str, unsigned int start)
{
	size_t	i;

	i = 0;
	if (start > ft_strlen(str))
		return (0);
	while (str[start] != '\0')
	{
		i++;
		start++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*newstring;

	i = 0;
	if (len > slen(s, start))
		len = slen(s, start);
	if (len == 0 || start > ft_strlen(s) || !s)
	{
		newstring = malloc(sizeof(char));
		if (newstring == NULL)
			return (NULL);
		newstring[0] = '\0';
		return (newstring);
	}
	newstring = malloc((len + 1) * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		newstring[i] = s[start + i];
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}
