/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_gram_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:34:05 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:34:07 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_GRAM_TYPE_H
# define SH_GRAM_TYPE_H

# include "libft.h"
# include "sh_sh.h"

typedef int	(t_exec)(t_sh*, void*);
typedef int	(t_wait)(t_sh*, void*, int op, int *state);
typedef int	(t_kill)(t_sh*, void*, int sig);

typedef struct	s_redir
{
	int		ion;
	int		op;
	char	*word;
}				t_redir;

typedef struct	s_simp_cmd
{
	t_dastr	*lst_assign;
	char	**envp;
	t_dastr	*lst_words;
	char	**argv;
	t_list	*lst_redir;
	pid_t	pid;
	int		wstat;
	int		state;
}				t_simp_cmd;

typedef struct	s_cmd
{
	void	*core;
	t_list	*lst_redir;
	int16_t	type;
	t_exec	*exec;
	t_wait	*wait;
	t_kill	*kill;
	t_free	tfree;
	int		stdioe[3];
	int		state;
}				t_cmd;

typedef struct	s_pipe
{
	t_list	*lst_cmd;
	t_dstr	*op;
	int8_t	neg;
}				t_pipe;

typedef struct	s_and_or
{
	t_list	*lst_pipe;
	t_dstr	*sep;
}				t_and_or;

typedef struct	s_com_cmd
{
	t_list	*lst_and_or;
	int		gr;
	t_dstr	*sep;
}				t_com_cmd;

typedef struct	s_com_cmds
{
	t_list	*lst_com_cmd;
}				t_com_cmds;

typedef struct	s_for
{
	t_dstr		*name;
	t_list		*lst_wordlist;
	t_com_cmd	*do_group;
}				t_for;

typedef struct	s_loop
{
	t_com_cmd	*cond;
	t_com_cmd	*do_group;
}				t_loop;

#endif
