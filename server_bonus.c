#include "libft/libft.h"
#include <signal.h>

void	ft_server(int signal, siginfo_t *info, void *add_data)
{
	static unsigned char	c;
	static int				i;

	(void)add_data;
	c = (c << 1) | (signal == SIGUSR1);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	usleep(150);
	if (signal == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signal == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sgac;
	
	sgac.sa_sigaction = &ft_server;
	sgac.sa_flags = SA_SIGINFO;
//	sigemptyset(&sgac.sa_mask); aún no entiendo
	ft_printf("El ID del servidor es: %i\n", getpid());
	sigaction(SIGUSR2, &sgac, NULL);
	sigaction(SIGUSR1, &sgac, NULL);
	while (1)
		pause();
	return (0);
}