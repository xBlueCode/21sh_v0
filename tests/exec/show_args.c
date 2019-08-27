#include <stdio.h>

int		main(int ac, char **av, char **envp)
{
	printf("---------- args_show ----------\n");
	if (ac < 2)
		dprintf(2, "Warning: %s: No args have been provided !!!\n", *av);
	for (int i = 1; i < ac; i++)
		printf("- arg %02d: <%s>\n", i, av[i]);
	printf("-------------------------------\n");
	return (0);
}
