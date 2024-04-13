/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 08:55:24 by jedusser          #+#    #+#             */
/*   Updated: 2023/12/06 15:35:10 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp;

	if (!lst || !f || !del)
	{
		return (NULL);
	}
	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = f(lst->content);
	tmp = new_list;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = malloc(sizeof(t_list));
		if (!(tmp->next))
			return (ft_lstclear(&new_list, del), NULL);
		tmp = tmp->next;
		tmp->content = f(lst->content);
	}
	tmp->next = NULL;
	return (new_list);
}
