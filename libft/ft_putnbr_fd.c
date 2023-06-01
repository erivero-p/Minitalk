/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:03:58 by erivero-          #+#    #+#             */
/*   Updated: 2023/04/24 10:27:27 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

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

void	ft_putnbr_fd(int n, int fd)
{
	int	i;
	int	c;

	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	i = ft_count(n);
	while (--i >= 0)
	{
		c = n / ft_pow(10, i);
		c = c % 10 + 48;
		ft_putchar_fd(c, fd);
	}
}
