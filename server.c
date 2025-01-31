/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:19:41 by jemorais          #+#    #+#             */
/*   Updated: 2025/01/31 15:01:02 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signo, siginfo_t *info, void *more_info)
{
	(void)more_info;
	write(STDOUT_FILENO, "HELLO\n", 6);

	printf("received: %d", signo, info->si_pid);
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, handler, true);
	signal(SIGUSR2, handler, true);
	while (42)
		pause();
	return (EXIT_SUCCESS);
}
