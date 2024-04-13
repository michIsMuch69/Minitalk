/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:02:00 by jedusser          #+#    #+#             */
/*   Updated: 2023/12/01 12:12:45 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	trimleft(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] && set[j])
	{
		if (s1[i] == set[j])
			i++;
		else if (s1[i] != set[j])
		{
			j = 0;
			while (s1[i] != set[j] && set[j] != '\0')
				j++;
		}
	}
	return (i);
}

static	int	trimright(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (i > 0 && set[j] && s1[i])
	{
		if (s1[i] == set[j])
			i--;
		else if (s1[i] != set[j])
		{
			j = 0;
			while (s1[i] != set[j] && set[j] != '\0')
				j++;
		}
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		startcpy;
	int		endcpy;

	startcpy = trimleft(s1, set);
	endcpy = trimright(s1, set);
	str = ft_substr(s1, startcpy, endcpy - startcpy + 1);
	if (str == NULL)
		return (NULL);
	if (ft_strlen(str) == 0)
	{
		str[0] = '\0';
	}
	return (str);
}
