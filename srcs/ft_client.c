#include "minitalk.h"
#include "libft.h"

void	send_bits(int pid, char byte)
{
	int	offset;

	offset = 0;
	while (offset < 7)
	{
		if ((byte >> offset) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		offset++;
		usleep(50);
	}
}

void	send_message(int pid, char *msg)
{
	int	i;
	int	len;

	i = 0;
	len = (int) ft_strlen(msg);
	while (i <= len)
	{
		send_bits(pid, msg[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_message(pid, argv[2]);
	}
	else
		ft_putstr_fd("Usage: ./client [server pid] [message]\n", 1);
	return (0);
}
