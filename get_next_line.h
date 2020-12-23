#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
int		ft_memset(char **line, size_t size);
void	ft_init(char *line, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_resize_and_copy(char **line, char *buf, int mul, int flag);
int		ft_while_loop(char **line, char *buf, int *st, int *mul);
int		get_next_line(int fd, char **line);
#endif
