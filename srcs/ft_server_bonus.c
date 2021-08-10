#include "minitalk_bonus.h"
#include "libft.h"

static t_message	g_message;
static pid_t		g_client_pid;

static void	init_message(void)
{
	g_message.byte = 0;
	g_message.offset = 0;
}

void	sig_handler(int sig, siginfo_t *info, void *unused)
{
	char	bit;

	(void) unused;
	if (!g_client_pid)
		g_client_pid = info->si_pid;
	bit = sig == SIGUSR1;
	g_message.byte += (bit << g_message.offset);
	g_message.offset++;
	if (g_message.offset == 8)
	{
		ft_putchar_fd(g_message.byte, 1);
		if (g_message.byte == '\0')
			ft_putchar_fd('\n', 1);
		g_message.byte = 0;
		g_message.offset = 0;
		kill(g_client_pid, SIGUSR1);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig_a;

	(void) argv;
	if (argc == 1)
	{
		init_message();
		ft_putstr_fd("Server PID: ", 1);
		ft_putnbr_fd(getpid(), 1);
		ft_putchar_fd('\n', 1);
		sig_a.sa_flags = SA_SIGINFO;
		sig_a.sa_sigaction = &sig_handler;
		sigaction(SIGUSR1, &sig_a, 0);
		sigaction(SIGUSR2, &sig_a, 0);
		while (1)
			pause();
	}
	else
		ft_putstr_fd("Usage: ./server\n", 1);
	return (0);
}
