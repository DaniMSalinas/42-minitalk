/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:07:00 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/20 11:17:08 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

/** simple functions **/
/* characters functions */
int		ft_atoi(const char *str);

/* memory functions */
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);

/* string functions */
size_t	ft_strlen(const char *s);
void	*ft_bzero(void *s, size_t n);

/** complex functions **/
char	*ft_strjoin(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
#endif
