#include "minitalk_bonus.h"
#include "libft.h"

static int	g_total_bytes;

static void	send_bits(int pid, unsigned char byte)
{
	int	offset;

	offset = 0;
	while (offset < 8)
	{
		if ((byte >> offset) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		offset++;
		usleep(50);
	}
}

static void	send_message(int pid, char *msg)
{
	int	i;
	int	len;

	i = 0;
	len = (int) ft_strlen(msg);
	while (i <= len)
	{
		send_bits(pid, (unsigned char) msg[i]);
		i++;
	}
}

static void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		g_total_bytes++;
		ft_putstr_fd("\rAcknowledged: ", 1);
		ft_putnbr_fd(g_total_bytes, 1);
	}
}

static void	init_total_bytes(void)
{
	g_total_bytes = 0;
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		init_total_bytes();
		pid = ft_atoi(argv[1]);
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		send_message(pid, argv[2]);
	}
	else
		ft_putstr_fd("Usage: ./client_bonus [server pid] [message]\n", 1);
	return (0);
}
