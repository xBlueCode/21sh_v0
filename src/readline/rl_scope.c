#include "ftsh.h"

extern t_rl g_rl;

int			rl_scope_prompt(char *str) {
	int i;

	i = -1;
	g_rl.plen = 0;
	//(void)str;
	while (str[++i])
		g_rl.plen += ft_printf("%s ", g_rl_scope_prompt[(int) str[i]]);
	ft_putstr("> ");
	g_rl.plen += 2;
//	ft_printf("plen: %d\n", g_rl.plen);
	return (0);
}
