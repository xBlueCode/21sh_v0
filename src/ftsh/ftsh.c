/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:12:43 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:12:45 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include <fcntl.h>

t_sh	*g_sh;

/*
** Run from a script file
** @param filename
** @param envp
** @return
*/

int		sh_file_run(char *filename, char **envp)
{
	t_dstr	*dscript;
	t_sh	*sh;
	int		ret;

	DF0;
	if (!(dscript = ft_read_file(filename)))
		return (KO);
	sh_sh_init(&sh, envp, SH_MODE_SCR);
	ret = sh_script_run(sh, dscript->str);
	ft_dstrfree(&dscript);
	sh_sh_free(&sh);
	return (ret);
}

/*
** Executes the script string
** @param sh
** @param script
** @return
*/

int		sh_script_run(t_sh *sh, char *script)
{
	t_lex		*lex;
	t_com_cmds	*com_cmds;
	int			ret;

	DF0;
	if (!script)
		return (1);
	sh_lex_init(&lex, script);
	if (sh_lex_start(lex) == KO)
		FT_INST_RET(KO, sh_lex_free(&lex));
	if (!lex->tlst)
		FT_INST_RET(KO, sh_lex_free(&lex));
	if (!(com_cmds = sh_p_start(lex)))
	{
		sh_lex_free(&lex);
		sh_g_com_cmds_free((void**)&com_cmds);
		return (KO);
	}
	sh_lex_free(&lex);
	ret = sh_e_com_cmds(sh, com_cmds);
	sh_g_com_cmds_free((void**)&com_cmds);
	return (ret);
}

/*
** Readline routine trigger
** @param line
** @return
*/

int		sh_inter_read(char **line)
{
	DF0;
	*line = rl_start();
	return (0);
}

/*
** Run from terminal
** @param envp
** @return
*/

int		sh_term_run(char **envp)
{
	char	*line;
	int		ret;

	if (sh_valid_stdin() == KO)
		return (KO);
	if (sh_sh_init(&g_sh, envp, SH_MODE_TER) != OK)
		exit(1);
	rl_hist_init(RL_HIS_FILENAME);
	rl_hist_upload();
	sh_als_init();
	rl_hist_print();
	line = NULL;
	while (1)
	{
		ret = 0;
		signal(SIGINT, &rl_sighand_parent);
		sh_inter_read(&line);
		rl_hist_add(line);
		ret = sh_script_run(g_sh, line);
		FT_MEMDEL(line);
		if (g_sh->quit)
			break ;
		g_sh->exit = ret;
	}
	FT_MEMDEL(line);
	rl_hist_save();
	rl_hist_free();
	if (g_sh->quit == 2)
		return (g_sh->quit_st);
	return (g_sh->exit);
}

/*
** @param ac
** @param av
** @param envp
** @return
*/

int		main(int ac, char **av, char **envp)
{
	int sh_est;

	if (ac > 1)
		sh_est = (sh_file_run(av[1], envp));
	else
	{
		sh_est = sh_term_run(envp);
		sh_termconfig_reset(&sh_sh()->term);
	}
	system("leaks -q 21sh");
	return (sh_est);
}
