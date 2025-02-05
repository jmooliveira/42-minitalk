/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:47:21 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/05 17:47:57 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*SERVER*/

#include "minitalk.h"

static int	char_completed(char **str, char *c, int *bit_c, siginfo_t *info)
{
	char	*temp;

	if (*c == 0)
	{
		ft_printf("%s\n", *str);
		free(*str);
		*bit_c = 0;
		*str = NULL;
		kill(info->si_pid, SIGUSR2);
		return (0);
	}
	temp = ft_strjoin(*str, c);
	free(*str);
	*str = temp;
	*c = 0;
	*bit_c = 0;
	return (1);
}

static void	print_signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static char	*str = NULL;
	static int	count_bit = 0;


	(void)context;
	c <<= 1;
	if (signum == SIGUSR1)
		c |= 0;
	else if (signum == SIGUSR2)
		c |= 1;
	if (!str)
	{
		str = ft_strdup("");
		puts("1");
	}
	count_bit++;
	if (count_bit == 8)
	{
		if (!char_completed(&str, &c, &count_bit, info))
			return ;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	//ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = print_signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID: %d\n", getpid());
	while(1)
		pause();
	return (0);
}
