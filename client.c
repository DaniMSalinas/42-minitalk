/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:43:01 by dmaldona          #+#    #+#             */
/*   Updated: 2023/06/17 13:32:31 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	g_pid;

char	*encode_binary(char *s)
{
	size_t	i;
	int		n;
	int		j;
	char	*message;

	if (!s)
		return (NULL);
	message = (char *)ft_calloc(ft_strlen(s) * 8 + 1, sizeof(char));
	if (!message)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s))
	{
		n = 7;
		while (n >= 0)
		{
			if (s[i] & (1 << n--))
				message[j++] = '1';
			else
				message[j++] = '0';
		}
		i++;
	}
	return (message);
}

void	send_message(char *ptr)
{
	size_t	len;
	size_t	i;
	int		result;

	len = ft_strlen(ptr);
	i = 0;
	result = 0;
	while (i < len)
	{
		if (ptr[i] == '0')
			result = kill(g_pid, SIGUSR1);
		else if (ptr[i] == '1')
			result = kill(g_pid, SIGUSR2);
		if (result == -1)
		{
			ft_putstr_fd("Error sending message\n", 1);
			exit(EXIT_FAILURE);
		}
		i++;
		usleep(200);
	}
	free(ptr);
	ptr = NULL;
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_putstr_fd("Usage : ./client <pid> <message_to_send>\n", 1);
		exit(EXIT_FAILURE);
	}
	g_pid = ft_atoi(argv[1]);
	if (g_pid <= 0)
	{
		ft_putstr_fd("Invalid pid\n", 1);
		exit(EXIT_FAILURE);
	}
	send_message(encode_binary(argv[2]));
	exit(EXIT_SUCCESS);
	return (0);
}
