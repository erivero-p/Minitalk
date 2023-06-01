/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:53:03 by erivero-          #+#    #+#             */
/*   Updated: 2023/04/28 16:55:34 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptr_print(unsigned long long ptr)
{
	int	count;

	count = 0;
	count += ft_str_print("0x");
	count += ft_hexa_print(ptr, 'x');
	return (count);
}
