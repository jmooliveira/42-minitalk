/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:19:48 by jemorais          #+#    #+#             */
/*   Updated: 2025/01/31 15:12:56 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// ./minitalk PID "message"

int main(int argc, char **argv)
{
	pid_t server;
	char *message;

	if(argc != 3)
	{
		fputs("Use: ./server <PID> 'Message'\n");
		exit(EXIT_FAILURE);
	}
	server = atoi(av[1]);
	message = av[2];
	while (*message)
	return (EXIT_SUCCESS);
}
