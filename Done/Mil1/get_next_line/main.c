#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	//fd = open("test_file_1.txt", O_RDONLY);
	fd = open("test_multiline.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file\n");
		return (1);
	}
	printf("Reading file line by line:\n");
	printf("-------------------------\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		line_count++;
		printf("Line %d: %s", line_count, line);
		if (line[ft_strlen(line) - 1] != '\n')
			printf("\n");
		free(line);
	}
	printf("-------------------------\n");
	printf("Total lines read: %d\n", line_count);
	close(fd);
	return (0);
}