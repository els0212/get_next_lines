#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int			st;
	ssize_t		rd;
	char		*temp;
	static char	*buf_ref;
	int			mul;
	char		temp_char;
#if BUFFER_SIZE > 0
	char		buf[BUFFER_SIZE];
#else
	char		buf[1];
#endif

	if (BUFFER_SIZE <= 0)
		return (-1);
	st = 0;
	mul = 1;
	ft_init((char *)buf, BUFFER_SIZE);
	*line = 0;
	while ((rd = read(fd, &buf[st], 1)) >= 0)
	{
		temp_char = buf[st];
		if (st == BUFFER_SIZE - 1)
		{
			ft_memset(&temp, BUFFER_SIZE * mul);
			if (mul > 1)
			{
				ft_strlcpy(temp, *line, BUFFER_SIZE * (mul - 1) + 1);
				free(*line);
			}
			ft_strlcpy(temp + BUFFER_SIZE * (mul - 1), buf, BUFFER_SIZE + 1);
			*line = temp;
			if (!temp_char || temp_char == '\n')
			{
				*(*line + BUFFER_SIZE * mul - 1) = '\0';
				break ;
			}
			st = -1;
			ft_init((char *)buf, BUFFER_SIZE);
			mul++;
		}
		else if (!temp_char || temp_char == '\n')
		{
			ft_memset(&temp, BUFFER_SIZE * (mul - 1) + st + 1);
			if (mul > 1)
			{
				ft_strlcpy(temp, *line, BUFFER_SIZE * (mul - 1) + 1);
	 			free(*line);
			}
			ft_strlcpy(temp + BUFFER_SIZE * (mul - 1), buf, st + 1);
			*line = temp;
			break ;
		}
		st++;
	}
	if(!(buf_ref = &buf[st]))
		return (-1);
	return ((int)rd);
}
