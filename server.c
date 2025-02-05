#include "minitalk.h"

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %d\n", getpid());
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_flags = SA_SIGINFO;
	//sa.sa_sigaction = print_signal; //print_signal
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(42)
		pause();
	return (0);
}