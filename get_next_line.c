ear* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyi <hyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:28:04 by hyi               #+#    #+#             */
/*   Updated: 2021/01/03 00:22:37 by hyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_get_len(char *str)
{
	int	st;

	if (!str || !*str)
		return (0);
	st = 0;
	while (str[st])
		st++;
	return (st);
}

int	ft_while_loop(char **line, char *buf, char **buf_ref)
{
	int	idx;
	int	st;

	idx = ft_get_new_line_idx(buf);
	//printf("idx = %d\n", idx);
	if (idx < 0)
		ft_resize_and_copy(line, buf, 0, BUFFER_SIZE);
	else
	{
		ft_resize_and_copy(line, buf, 0, idx);
		*buf_ref = idx < BUFFER_SIZE - 1 ? ft_strdup(&buf[idx + 1]) : 0;

		//printf("in while loop buf_ref = :%s:\n", *buf_ref);
		return (1);
	}
	st = 0;
	while (buf[st])
		buf[st++] = '\0';
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*buf_ref;
	char		*buf;
	ssize_t		rd;
	int			idx;

	if (!line || BUFFER_SIZE <= 0)
		return (-1);
	*line = 0;
	if (buf_ref)
	{
		//printf("buf_ref = :%s:\n", buf_ref);
		if (ft_get_new_line_idx(buf_ref) >= 0 && ft_get_new_line_idx(buf_ref) < BUFFER_SIZE - 1)
		{
			ft_resize_and_copy(line, buf_ref, 0, ft_get_new_line_idx(buf_ref));
			buf_ref = &buf_ref[ft_get_new_line_idx(buf_ref)];
			return (1);
		}
		else
			ft_resize_and_copy(line, buf_ref, 0, ft_get_len(buf_ref));
		buf_ref = 0;
	}
	ft_memset(&buf, BUFFER_SIZE);
	while ((rd = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		//printf("loop buf = :%s:\n", buf);
		//printf("rd = %ld\n", rd);
		if (ft_while_loop(line, buf, &buf_ref))
			break;
	}
	free(buf);
	if (!rd)
		return (0);
	return (rd > 0 ? 1 : -1);
}
