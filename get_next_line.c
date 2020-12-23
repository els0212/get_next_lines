#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int			st;
	char		buf[BUFFER_SIZE];
	ssize_t		rd;
	char		*temp;
	static char	*buf_ref;
	int			mul;
	char		temp_char;

	st = 0;
	mul = 1;
	ft_init((char *)buf, BUFFER_SIZE);
	rd = read(fd, &buf[st++], 1);
	if (rd <= 0)
		return ((int)rd);
	if (st == BUFFER_SIZE || buf[0] == '\n')
	{
		ft_memset(&temp, BUFFER_SIZE * mul++);
		ft_strlcpy(temp, buf, BUFFER_SIZE + 1);
		*line = temp;
		st = 0;
		if (buf[0] == '\n')
			return ((int)rd);
		buf[0] = '\0';
	}
	//printf("st = %d, rd = %ld, buf[st] = %c\n",st, rd, buf[st - 1]);
	while ((rd = read(fd, &buf[st], 1)) >= 0)
	{
		temp_char = buf[st];
		//printf("st = %d, rd = %ld, buf[st] = %c\n",st, rd, buf[st]);
		if (st >= BUFFER_SIZE - 1)
		{
			//printf("buf full st = %ld, buf = %s, *line = %s\n",rd, buf, *line);
			ft_memset(&temp, BUFFER_SIZE * mul);
			if (mul > 1)
			{
				ft_strlcpy(temp, *line, BUFFER_SIZE * (mul - 1) + 1);
				free(*line);
			}
			ft_strlcpy(temp + BUFFER_SIZE * (mul - 1), buf, BUFFER_SIZE + 1);
			*line = temp;
			st = -1;
			ft_init((char *)buf, BUFFER_SIZE);
			//printf("buffer full *line = %s\n", *line);
			mul++;
		}
		if (!temp_char || temp_char == '\n')
		{
			//printf("\\n find st = %ld, buf = %s, *line = %s\n",rd, buf, *line);
			ft_memset(&temp, BUFFER_SIZE * (mul - 1) + st);
			if (mul > 1)
			{
				ft_strlcpy(temp, *line, BUFFER_SIZE * (mul - 1) + 1);
	 			free(*line);
			}
			ft_strlcpy(temp + BUFFER_SIZE * (mul - 1), buf, st + 1);
			*line = temp;
			//printf("new line *line = %s\n", *line);
			break ;
		}
		st++;
	}
	//printf("out ! st = %d, rd = %ld, buf[st] = %c\n",st, rd, buf[st]);
	if(!(buf_ref = &buf[st]))
		return (-1);
	return ((int)rd);
}
/*
int main(void)
{
	char *ret;
	get_next_line(0, &ret);
	printf("%s", ret);
}
*/
