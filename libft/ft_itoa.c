/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:06:28 by erivero-          #+#    #+#             */
/*   Updated: 2023/05/01 16:27:03 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

static int	ft_count(long int nb)
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

char	*ft_itoa(int n)
{
	int				i;
	long int		res;
	char			*num;

	res = n;
	i = 0;
	if (n < 0)
	{
		res *= -1;
		i = 1;
	}
	i = ft_count(res) + i;
	num = malloc((i + 1) * sizeof(char));
	if (!num)
		return (NULL);
	num[i--] = '\0';
	while (i >= 0)
	{
		num[i--] = res % 10 + 48;
		res /= 10;
	}
	if (n < 0)
		num [0] = '-';
	return (num);
}
