/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:47:29 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/05 17:35:23 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*HEADER*/

#ifndef MINITALK_H
# define MINITALK_H

# define _POSIX_C_SOURCE 200809L // ?
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// # include <stddef.h>
// # include <sys/types.h>

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

// server
//void	print_signal_handler(int signum, siginfo_t *info, void *context);
//int		char_completed(char **str, char *c, int *bit_c, siginfo_t *info);

// client
void	send_bit(int pid, char bit);
void	send_char(int pid, char c);
void	send_string(int pid, char *str);

#endif
