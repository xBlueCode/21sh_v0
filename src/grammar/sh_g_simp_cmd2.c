/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_g_simp_cmd2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:45:25 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/20 21:45:27 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

void			*sh_g_simp_cmd_new(void)
{
	t_simp_cmd *simp_cmd;

	SHG_CHECK_MALL(simp_cmd);
	simp_cmd->lst_assign = ft_dastrnew_max(2);
	simp_cmd->lst_redir = NULL;
	simp_cmd->lst_words = ft_dastrnew_max(2);
	simp_cmd->envp = NULL;
	simp_cmd->argv = NULL;
	simp_cmd->pid = -1;
	simp_cmd->state = -1;
	return (simp_cmd);
}

void			sh_g_simp_cmd_free(void **g)
{
	t_simp_cmd	**simp_cmd;

	DF0;
	simp_cmd = (t_simp_cmd**)g;
	ft_dastrfree(&(*simp_cmd)->lst_assign);
	ft_dastrfree(&(*simp_cmd)->lst_words);
	ft_arr_free((void***)&(*simp_cmd)->envp,
				ft_arr_len((void**)(*simp_cmd)->envp));
	ft_arr_free((void***)&(*simp_cmd)->argv,
				ft_arr_len((void**)(*simp_cmd)->argv));
	ft_lst_free(&(*simp_cmd)->lst_redir, &sh_g_redir_free);
	FT_MEMDEL(*g);
}
