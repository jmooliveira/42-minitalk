/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:47:26 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/10 14:45:26 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*CLIENT*/

#include "minitalk_bonus.h"

int	g_wait_response = 0;

static void	handle_response(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("Message OK!\n");
	g_wait_response = 1;
}

static void	send_bit(int pid, char bit)
{
	g_wait_response = 0;
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	while (!g_wait_response)
		;
}

static void	send_char(int pid, char c)
{
	int		i;
	char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = ((c >> i) & 1);
		printf("%c", bit);
		send_bit(pid, bit);
		i--;
	}
}

static void	send_string(int pid, char *str)
{
	int	i;

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
	char	*message;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		message = av[2];
		signal(SIGUSR1, handle_response);
		signal(SIGUSR2, handle_response);
		send_string(pid, message);
	}
	else
	{
		ft_printf("Error\n%s <PID> \"message\"\n", av[0]);
		return (1);
	}
	return (0);
}
