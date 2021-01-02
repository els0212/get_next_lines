#include "get_next_line.h"
#include <stdio.h>
int main(void)
{
	char *line;
	while (get_next_line(0, &line))
		printf("line = %s", line);
	return (0);
}
