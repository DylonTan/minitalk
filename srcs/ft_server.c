#include "minitalk.h"
#include "libft.h"

static t_message	g_message;

static void	init_message(void)
{
	g_message.byte = 0;
	g_message.offset = 0;
}

static void	sig_handler(int sig)
{
	char	bit;

	bit = sig == SIGUSR1;
	g_message.byte += (bit << g_message.offset);
	g_message.offset++;
	if (g_message.offset == 7)
	{
		ft_putchar_fd(g_message.byte, 1);
		if (g_message.byte == '\0')
			ft_putchar_fd('\n', 1);
		g_message.byte = 0;
		g_message.offset = 0;
	}
}

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc == 1)
	{
		init_message();
		ft_putstr_fd("Server PID: ", 1);
		ft_putnbr_fd(getpid(), 1);
		ft_putchar_fd('\n', 1);
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		while (1)
			pause();
	}
	else
		ft_putstr_fd("Usage: ./server\n", 1);
	return (0);
}
