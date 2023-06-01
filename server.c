#include "libft/libft.h"
#include <signal.h>

void	ft_server(int signal)
{
	static unsigned char	c;
	static int				i;

	c = (c << 1) | (signal == SIGUSR1);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_printf("El ID del servidor es: %i\n", getpid());
	signal(SIGUSR2, ft_server);
	signal(SIGUSR1, ft_server);
	while (1)
		pause();
	return (0);
}