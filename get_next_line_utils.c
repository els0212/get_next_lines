/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyi <hyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:28:14 by hyi               #+#    #+#             */
/*   Updated: 2020/12/24 00:28:14 by hyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_memset(char **line, size_t size)
{
	if (!(*line = (char *)malloc(sizeof(char) * (size + 1))))
		return (-1);
	ft_init(*line, size);
	return (0);
}

void	ft_init(char *line, size_t size)
{
	size_t	st;

	st = 0;
	while (st < size)
		*(line + st++) = 0;
}

size_t	ft_strlen(const char *s)
{
	int	st;

	st = 0;
	while (*(s + st))
		st++;
	return (st);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	st;

	st = 0;
	while (src[st] && st + 1 < dstsize)
	{
		dst[st] = src[st];
		st++;
	}
	if (dstsize > 0)
		dst[st] = '\0';
	return (ft_strlen(src));
}

int		ft_resize_and_copy(char **line, char *buf, int mul, int flag)
{
	char	*temp;
	int		mem_size;
	int		cpy_size;

	mem_size = flag == -1 ? BUFFER_SIZE * mul :
		BUFFER_SIZE * (mul - 1) + flag + 1;
	cpy_size = flag == -1 ? BUFFER_SIZE + 1 : flag + 1;
	ft_memset(&temp, mem_size);
	if (mul > 1)
	{
		ft_strlcpy(temp, *line, BUFFER_SIZE * (mul - 1) + 1);
		free(*line);
	}
	ft_strlcpy(temp + BUFFER_SIZE * (mul - 1), buf, cpy_size);
	*line = temp;
	return (mul);
}
