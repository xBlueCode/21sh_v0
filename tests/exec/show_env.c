#include <stdio.h>

int		main(int ac, char **av, char **envp)
{
	printf("---------- env_show -----------\n");
	while (*envp)
	{
		printf("- %s\n", *envp);
		envp++;
	}
	printf("-------------------------------\n");
	return (0);
}
