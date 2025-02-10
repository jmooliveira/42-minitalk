/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:47:21 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/07 17:21:24 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*SERVER*/

#include "minitalk.h"

void	ft_confirm(siginfo_t *pid)
{
	kill(pid->si_pid, SIGUSR2);
}

static void	print_signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static char	*str = NULL;
	static int	count_bit = 0;

	(void)context;
	if (!str)
		str = ft_strdup("");
	if (signum == SIGUSR2)
		c |= 1 << (7 - count_bit);
	count_bit++;
	if (count_bit == 8)
	{
		str = ft_strjoin(str, &c);
		if (c == '\0')
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
			ft_confirm(info);
		}
		count_bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %d\n", getpid());
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = print_signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (42)
		pause();
	return (0);
}
