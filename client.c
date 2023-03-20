/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:43:01 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/20 12:40:41 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	g_pid;

void	c_encode_binary(char c, char **binary)
{
	int		n;
	int		i;

	n = 7;
	i = 0;
	while (n >= 0)
	{
		if (c & (1 << n--))
			(*binary)[i++] = '1';
		else
			(*binary)[i++] = '0';
	}
}

char	*encode_binary(char *s)
{
	size_t	len;
	size_t	i;
	char	*message;
	char	*binary;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	message = (char *)ft_calloc(len * 8, sizeof(char));
	binary = (char *)ft_calloc(8, sizeof(char));
	if (!message || !binary)
		return (NULL);
	i = 0;
	while (i < len)
	{
		c_encode_binary(s[i++], &binary);
		message = ft_strjoin(message, binary);
	}
	free(binary);
	binary = NULL;
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
