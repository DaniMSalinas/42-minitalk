/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:48:12 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/19 22:46:20 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	c_decode_binary(char *s)
{
	int	n;
	int	i;
	int	res;

	if (!s)
		return (0);
	n = 7;
	i = 0;
	res = 0;
	while (n >= 0)
		res += (1 << n--) * (s[i++] - 48);
	return (res);
}

void	message_handler(int sig)
{
	static int	bits = 0;
	char		binary[8];
	char		c;

	if (sig == SIGUSR1)
		binary[bits] = '0';
	else if (sig == SIGUSR2)
		binary[bits] = '1';
	bits++;
	if (bits == 8)
	{
		c = c_decode_binary(binary);
		write(1, &c, 1);
		bits = 0;
		usleep(50);
	}
}

int	main(void)
{
	pid_t				pid;

	pid = 0;
	signal(SIGUSR1, message_handler);
	signal(SIGUSR2, message_handler);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (42)
		;
	return (0);
}
