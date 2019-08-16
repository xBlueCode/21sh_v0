#include "stdio.h"
#include "stdlib.h"

/**
 * Testing var assignments (uses home.sh script for comparing)
 */
int main(int ac, char **av)
{
	int		i;
	char	cmd[256];

	i = -1;
	printf("Args:\n");
	printf("------------------\n");
	while (++i < ac)
		printf("\t%d: '%s'\n", i, av[i]);
	printf("------------------\n");
	system("echo $HOME");
	i = 0;
	while (++i < ac)
	{
		sprintf(cmd, "echo $%s", av[i]);
		system(cmd);
	}
	printf("------------------\n");
	return (0);
}
