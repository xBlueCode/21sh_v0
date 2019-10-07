/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_expan.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:34:01 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:34:03 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXPAN_H
# define SH_EXPAN_H

# include "sh_lex.h"
# include "sh_exec.h"

int		sh_xp_word(t_sh *sh, t_dastr *words);
int		sh_xp_assign(t_sh *sh, t_dastr *assigns);

int 	sh_xp_brace(t_sh *sh, t_dastr *words, int *i, int *j);

int 	sh_xp_param(t_sh *sh, t_dastr *words, int *i, int *j);

int 	sh_xp_bq(t_sh *sh, t_dastr *words, int *i, int *j);
int 	sh_xp_scmd(t_sh *sh, t_dastr *words, int *i, int *j);

int 	sh_xp_var(t_sh *sh, t_dastr *words, int *i, int *j);

int 	sh_xp_dq(t_sh *sh, t_dastr *words, int *i, int *j);
int 	sh_xp_sq(t_sh *sh, t_dastr *words, int *i, int *j);
int 	sh_xp_esc(t_sh *sh, t_dastr *words, int *i, int *j);

int 	sh_xp_tilde(t_sh *sh, t_dastr *words, int *i, int *j);


int		sh_xp_word_split(t_sh *sh, t_dastr *words);

#endif
