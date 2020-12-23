#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
int		get_next_line(int fd, char **line);
int		ft_memset(char **line, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_init(char *line, size_t size);
#endif
