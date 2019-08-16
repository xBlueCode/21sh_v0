#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int		main (int ac, char **av)
{

	char	*filename;
	int		times;
	int		fd1;
	int		fd2;

	if (ac != 3 && printf("Bad Args !\n"))
		return (1);
	filename = "filedup";
	if ((fd1 = open(filename, O_CREAT | O_APPEND | O_RDWR)) < 0)
	{
		printf("Failed to open the file\n");
		return (1);
	}
	//fd2 = dup(fd1);
	fd2 = 5000;
	printf("--> tabledsize: %d\n", getdtablesize());
	if (dup2(fd1, fd2) < 0)
	{
		printf("Error: dup2\n");
		return (1);
	}
	printf("fd1= %d , fd2= %d\n", fd1, fd2);
	times = -1;
	/*
	while (++times < 10)
		write(fd1, av[1], strlen(av[1]));
	*/
	while (++times < 10)
		if (0 > (write(times % 2 ? fd1 : fd2, av[2 - times % 2], strlen(av[2 - times % 2]))))
			return (1);
	write(fd1, "\n", 1);
	return (0);
}
