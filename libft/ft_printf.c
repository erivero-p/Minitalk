/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:37:50 by erivero-          #+#    #+#             */
/*   Updated: 2023/05/01 12:51:32 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_filter(char const *fix, int i, va_list *arg)
{
	int	count;

	count = 0;
	if (fix[i] == 'c')
		count += ft_puchero(va_arg(*arg, int));
	if (fix[i] == 's')
		count += ft_str_print(va_arg(*arg, char *));
	if (fix[i] == 'u')
		count += ft_unsign_print(va_arg(*arg, unsigned int));
	if (fix[i] == 'i')
		count += ft_int_print(va_arg(*arg, int));
	if (fix[i] == 'd')
		count += ft_int_print(va_arg(*arg, int));
	if (fix[i] == 'x' || fix[i] == 'X')
		count += ft_hexa_print(va_arg(*arg, unsigned int), fix[i]);
	if (fix[i] == 'p')
		count += ft_ptr_print(va_arg(*arg, unsigned long long));
	if (fix[i] == '%')
		count += ft_puchero('%');
	return (count);
}

int	ft_printf(char const *fix, ...)
{
	int		i;
	int		count;
	va_list	arg;

	i = 0;
	count = 0;
	va_start(arg, fix);
	while (fix[i])
	{
		if (fix[i] != '%')
			count += ft_puchero(fix[i]);
		else
		{
			i++;
			count += ft_filter(fix, i, &arg);
		}
		i++;
	}
	va_end(arg);
	return (count);
}

/* #include <stdio.h>
int	main(void)
{
	int c = 421;
	int i = 0;
	//ft_printf("El resultado es %i", c);
	i = ft_printf("%i", c);
	printf("%i", i);
} */