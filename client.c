/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:47:26 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/05 17:59:45 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*CLIENT*/

#include "minitalk.h"

//#include <unistd.h>

int	g_wait_response = 0;

static void	handle_response(int signal)
{
	(void)signal;
	g_wait_response = 1;
}

void	send_bit(int pid, char bit)
{
	g_wait_response = 0;
	if(bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	// usleep(100);
	while (!g_wait_response)
		;
}

void	send_char(int pid, char c)
{
	int		i;
	char	bit;

	i = 0;
	// bit = 0;
	while (i < 8)
	{
		bit = (c >> i) & 1;
		send_bit(pid, bit);
		i++;
	}
}

void	send_string(int pid, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int ac, char **av)
{
	int		pid;


	signal(SIGUSR1, handle_response);
	signal(SIGUSR2, handle_response);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send_string(pid, av[2]);
	}
	else
	{
		ft_printf("Error\n%s <PID> \"message\"\n", av[0]);
		return (1);
	}
	return (0);
}
