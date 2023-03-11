/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:16:48 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/11 18:16:53 by dmaldona         ###   ########.fr       */
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

char	*decode_binary(char *s)
{
	size_t	len;
	size_t	n;
	char	*str;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)ft_calloc(len / 8 + 1, sizeof(char));
	if (!str)
		return (NULL);
	n = 0;
	while (n < len / 8)
	{
		str[n] = c_decode_binary(&s[n * 8]);
		n++;
	}
	return (str);
}
