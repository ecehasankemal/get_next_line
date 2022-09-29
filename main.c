#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

// O_RDONLY zaten var olan dosyayı okumak için ve sadece okumaya açık

int	main()
{
	int fd;
	fd = open("./test.html",O_RDONLY);
	printf("%d", fd);
	while(1)
	{
		char *line = get_next_line(fd);
		if(line == NULL)
		{
			break ;
		}
		printf("%s",line);
		free(line);
	}
	system("leaks a.out");
	
}
