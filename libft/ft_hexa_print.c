/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:52:37 by erivero-          #+#    #+#             */
/*   Updated: 2023/05/10 15:09:17 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexa_print(unsigned long long n, char c)
{
	unsigned int	count;

	count = 0;
	if (n >= 16)
		count += ft_hexa_print(n / 16, c);
	if (c == 'x')
		ft_puchero("0123456789abcdef"[n % 16]);
	if (c == 'X')
		ft_puchero("0123456789ABCDEF"[n % 16]);
	count++;
	return (count);
}
