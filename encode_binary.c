/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:38:32 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/09 14:57:41 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	main(void)
{
	printf("%s\n", encode_binary("dani"));
	return (0);
}
