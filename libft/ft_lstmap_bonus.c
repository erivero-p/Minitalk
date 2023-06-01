/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:46:46 by erivero-          #+#    #+#             */
/*   Updated: 2023/04/26 17:39:31 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy;
	t_list	*ptr;

	if (!lst)
		return (NULL);
	cpy = 0;
	while (lst)
	{
		ptr = ft_lstnew(f(lst->content));
		if (ptr)
		{
			ft_lstadd_back(&cpy, ptr);
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&cpy, del);
			return (0);
		}
	}
	return (cpy);
}
