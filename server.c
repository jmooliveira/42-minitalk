#include "minitalk.h"

void	handler(int signo, siginfo_t *info, void *more_info)
{
	(void)more_info;


}

int	main(void)
{
	printf("Server PID: %d\n", getpid());

	Signal(SIGUSR1, handler, true);
	Signal(SIGUSR2, handler, true);
	while (42)
		pause;
	return (EXIT_SUCCESS);
}
