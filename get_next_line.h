/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyi <hyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:28:10 by hyi               #+#    #+#             */
/*   Updated: 2021/01/02 21:49:40 by hyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
int		ft_memset(char **line, size_t size);
void	ft_init(char *line, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_resize_and_copy(char **line, char *buf, int st, int ed);
int		ft_while_loop(char **line, char *buf, char **buf_ref);
int		get_next_line(int fd, char **line);
int		ft_get_new_line_idx(char *buf);
char	*ft_strdup(char *str);
int		ft_get_len(char *str);
#endif
