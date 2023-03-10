/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:43:01 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/10 15:03:45 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	pid;

char	*c_encode_binary(char c, char **binary)
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
	return (*binary);
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
	binary = (char *)ft_calloc(9 + 1, sizeof(char));
	if (!message || !binary)
		return (NULL);
	i = 0;
	while (i < len)
	{
		binary = c_encode_binary(s[i++], &binary);
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

	len = ft_strlen(ptr);
	i = 0;
	while (i < len){
		if (ptr[i] == 48)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		if (ptr[i] == 49)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		i++;
		usleep(2);
	}
}

int main(int argc, char *argv[])
{
    if (argc != 3)
	{
		ft_putstr_fd("Usage : ./client <pid> <message_to_send>\n", 1);
        exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	send_message(encode_binary(argv[2]));
    return (0);
}