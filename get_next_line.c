#include "get_next_line.h"

int	ft_while_loop(char **line, char *buf, int *st, int *mul)
{
	if (*st == BUFFER_SIZE - 1)
	{
		*mul = ft_resize_and_copy(line, buf, *mul, -1);
		if (!buf[*st] || buf[*st] == '\n')
		{
			*(*line + BUFFER_SIZE * (*mul) - 1) = '\0';
			return (1);
		}
		*st = -1;
		ft_init(buf, BUFFER_SIZE);
		(*mul)++;
	}
	else if (!buf[*st] || buf[*st] == '\n')
	{
		ft_resize_and_copy(line, buf, *mul, *st);
		return (1);
	}
	(*st)++;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*buf_ref;
	char		*buf;
	int			st;
	int			mul;
	ssize_t		rd;

	if (BUFFER_SIZE <= 0)
		return (-1);
	*line = 0;
	st = 0;
	mul = 1;
	ft_memset(&buf, BUFFER_SIZE);
	while ((rd = read(fd, &buf[st], 1)) >= 0)
		if (ft_while_loop(line, buf, &st, &mul))
			break ;
	return (!(buf_ref = &buf[st]) ? -1 : rd);
}
