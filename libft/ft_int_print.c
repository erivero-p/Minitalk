/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:03:58 by erivero-          #+#    #+#             */
/*   Updated: 2023/05/10 15:09:22 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int nb)
{
	unsigned int	i;

	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static int	ft_pow(int a, int b)
{
	int	res;

	res = 1;
	while (b-- > 0)
		res = a * res;
	return (res);
}

static void	ft_putnbr(int n)
{
	int	i;
	int	c;

	if (n == -2147483648)
	{
		ft_puchero('-');
		ft_puchero('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_puchero('-');
		n *= -1;
	}
	i = ft_count(n);
	while (--i >= 0)
	{
		c = n / ft_pow(10, i);
		c = c % 10 + 48;
		ft_puchero(c);
	}
}

int	ft_int_print(int n)
{
	int	count;

	count = ft_count(n);
	ft_putnbr(n);
	if (n == -2147483648)
		count = 2 + ft_count(147483648);
	else if (n < 0)
		count = 1 + ft_count(n * -1);
	return (count);
}

/* #include <stdio.h>
int	main (void)
{
	int i = -21483648;
	printf("%i", ft_int_print(i));
}
 */