/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:20:42 by erivero-          #+#    #+#             */
/*   Updated: 2023/05/01 16:28:54 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*ptr_dest;
	char	*ptr_src;

	if (src == NULL && dst == NULL)
		return (0);
	i = 0;
	ptr_dest = (char *)dst;
	ptr_src = (char *)src;
	if (ptr_dest > ptr_src)
	{
		while (len-- != 0)
			ptr_dest[len] = ptr_src[len];
	}
	else
	{
		while (i < len)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	return (dst);
}
