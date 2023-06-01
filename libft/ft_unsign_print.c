/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:03:58 by erivero-          #+#    #+#             */
/*   Updated: 2023/05/10 15:09:52 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int	ft_unsign_print(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_unsign_print(n / 10);
	ft_puchero((n % 10) + 48);
	count++;
	return (count);
}
