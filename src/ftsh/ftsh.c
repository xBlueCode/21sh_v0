// header

#include "ftsh.h"

t_term	g_term;

int		sh_file_run(char *filename)
{
	ft_putendl(filename);
	if (filename)
		return (0);
	return (1);
}

int		sh_script_run(char *script)
{
	if (script)
		return (0);
	return (1);
}

int		sh_inter_read(char **line)
{
	//(void)line;
	//prompt_display();
	//signal(SIGINT, sighand_parent);
	//get_inline(line);
	*line = rl_start();
	return (0);
}

int		sh_inter_run(void)
{
	char	*line;
	t_lex	*lex;

	//init_hist
	//rl_hist_init("/home/xbluecode/ft/ftsh/history/.ftsh_history"); // replace arg by _getpath
	rl_hist_init(RL_HIS_FILENAME);
	rl_hist_upload();
	rl_hist_print();
	sh_termconfig_init();
	line = "";
	while (ft_strcmp(line, "exit\n"))
	{
		sh_inter_read(&line);
	//	ft_printf("in run: line: <%s>\n", line);
		rl_hist_add(line);
		sh_lex_init(&lex, line);
		sh_lex_start(lex);
		//rl_cleanup();
		//if (sh_script_run(line) == EXIT)
		//{
		//	ft_memdel((void**)&line);
		//	return (OK);
		//}
		//ft_memdel((void**)&line);
	}
	rl_hist_save();
	return (0);
}

int		main(int ac, char **av, char **envp)
{
	int sh_est;

	(void)ac;
	(void)av;
	//(void)envp;
	sh_var_start(envp);
	//ft_tabdel_n(sh_env_get(), "LS_COLORS");
	//ft_tabdel_i(sh_env_get(), 2);
	ft_tabins(sh_var(), ft_tabrow_set(0, "NEW", "nvalue120", 0), 0);
	ft_tabput(sh_var(), "=");
	//sh_invar_init();
	//sh_hash_init();
	//if (ac > 1)
	//	sh_est = (sh_file_run(av[1]));
	//else
		sh_est = (sh_inter_run());
	sh_termconfig_reset();
	//sh_cleanup();
	return (sh_est);
}
