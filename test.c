#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	char *line;
	int fd = open("test2",O_RDONLY);
	while (get_next_line(fd, &line))
		printf("line = %s", line);
	return (0);
}
