#include "libft/libft.h"
#include <signal.h>

void	send_bits(int pid, unsigned char octet)
{
	unsigned char	u;

	u = 128;
	while (u > 0)
	{
		if (octet & u)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		u >>= 1;
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	int				pid;
	int				i;
	unsigned char	octet;

	if (ac != 3)
		ft_printf("parámetros no válidos\n");
	else
	{
		pid = ft_atoi(av[1]);
		i = 0;
		while (av[2][i])
		{
			octet = (unsigned char)av[2][i];
			send_bits(pid, octet);
			i++;
		}
		ft_printf("\nSe han enviado %i caracteres\n", i);
	}
}