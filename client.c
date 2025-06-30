/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:14:07 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/06/30 12:51:02 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t server_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(300);
		i--;
	}
}

static void	action(int sig)
{
	static int	received;

	received = 0;
	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putnbr(received);
		ft_putchar('\n');
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;
	int		i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr("Usage: ./client <PID> <message>\n");
		return (1);
	}
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	while (msg[i])
	{
		send_char(pid, msg[i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}
