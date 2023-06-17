/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:48:12 by dmaldona          #+#    #+#             */
/*   Updated: 2023/06/17 14:12:04 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	message_handler(int sig)
{
	static char	ch;
	static int	i;

	(void) sig;
	if (sig == 30)
		ch = (ch << 1);
	if (sig == 31)
		ch = (ch << 1) + 1;
	i++;
	if (i == 8)
	{
		write(1, &ch, 1);
		ch = '\0';
		i = 0;
	}	
}

int	main(void)
{
	pid_t				pid;

	pid = 0;
	signal(SIGUSR1, message_handler);
	signal(SIGUSR2, message_handler);
	pid = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (42)
		sleep(42);
	return (0);
}
