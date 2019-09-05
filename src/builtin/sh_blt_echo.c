#include "ftsh.h"

int 	sh_blt_echo(t_sh *sh, char **argv, char **envp)
{
	uint8_t op;
	int 	i;

	(void)envp;
	if (!argv)
		return (1);
	op = 0;
	i = 1;
	if (argv[i] && !ft_strcmp(argv[i], "-n") && i++)
		op = 1;
	while (argv[i])
	{
		if (argv[i + 1])
		{
			ft_putstr(argv[i++]);
			ft_putchar(' ');
		}
		else
			break;
	}
	if (argv[i])
		ft_putstr(argv[i]);
	if (!op)
		ft_putchar('\n');
	return (0);
}
