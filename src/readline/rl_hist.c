// header

#include <fcntl.h>
#include "ftsh.h"

t_hist		g_his;

int 		rl_hist_init(char *filename)
{
	if (filename)
		g_his.filename = ft_strdup(filename);
	else
		g_his.filename = ft_strdup(HIS_FILENAME);
	g_his.ent = ft_dastrnew_max(1024);
	g_his.back = NULL;
	g_his.cur = 0;
	g_his.off = 0;
}

int			rl_hist_parse(char *str, int num)
{
	t_dastr		*ent;
	char 		*line;
	ssize_t		etx;

	//ft_printf("hist_parsing str: <%s>, num <%d>\n", str, num);
	if (!str || num < 1)
		return (-1);
	//ent = ft_dastrnew_max(num);
	ent = g_his.ent;
	while (--num > -1)
	{
		if ((etx = ft_strichr(str, 0x03)) < 0)
			break;
		line = ft_strndup(str, etx);
		str = str + etx + 1;
		ft_dastrins_str(ent, -1, line);
		ft_memdel((void**)&line);
	}
	return (0);
}

int 		rl_hist_add(char *line)
{
	if (!line || !*line || *line == '\n')
		return (-1);
	ft_dastrins_str(g_his.ent, -1, line);
	g_his.cur = g_his.ent->len - 1;
	return (0);
}

int			rl_hist_print(void)
{
	int i;

	ft_printf("FTSH History, Total: %d\n", g_his.ent->len);
	if (!g_his.ent || !g_his.ent->a)
		return (-1);
	i = -1;
	while (g_his.ent->a[++i])
		if (g_his.ent->a[i]->str)
		{
			ft_putnbr(i);
			ft_putchar('\t');
			ft_putstr(g_his.ent->a[i]->str);
		}
	return (0);
}