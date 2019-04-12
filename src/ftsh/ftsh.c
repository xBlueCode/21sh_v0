/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 19:06:00 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/17 13:59:35 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	(void)line;
	//prompt_display();
	//signal(SIGINT, sighand_parent);
	//get_inline(line);
	rl_start();
	return (0);
}

int		sh_inter_run(void)
{
	char	*line;

	//sh_history_upload(g_hist.filename);
	sh_termconfig_init();
	while (1)
	{
		sh_inter_read(&line);
		//sh_history_add(g_rl.lines);
		//rl_cleanup();
		//if (sh_script_run(line) == EXIT)
		//{
			//ft_memdel((void**)&line);
		//	return (OK);
		//}
		//ft_memdel((void**)&line);
	}
}

int		main(int ac, char **av, char **envp)
{
	int sh_est;

	(void)ac;
	(void)av;
	(void)envp;
	//sh_env_init(envp);
	//sh_invar_init();
	//sh_hash_init();
	//if (ac > 1)
	//	sh_est = (sh_file_run(av[1]));
	//else
		sh_est = (sh_inter_run());
	//sh_termconfig_reset();
	//sh_cleanup();
	return (sh_est);
}

