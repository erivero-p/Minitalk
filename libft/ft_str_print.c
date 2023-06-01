/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:36:30 by erivero-          #+#    #+#             */
/*   Updated: 2023/05/01 10:28:30 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_print(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_str_print("(null)"));
	while (str[i])
	{
		ft_puchero(str[i]);
		i++;
	}
	return (i);
}
