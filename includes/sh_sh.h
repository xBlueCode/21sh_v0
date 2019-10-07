/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:34:23 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:34:25 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include "sh_jctype.h"
//# include "sh_jobc.h"
# include "libft.h"


# define SH_MODE_TER	0x01
# define SH_MODE_INT	0x02
# define SH_MODE_SCR	0x04
# define SH_MODE_SSH	0x08
# define SH_MODE_SCMD	0x10
# define SH_MODE_ENV	0x20
# define SH_MODE_M		0xff

# define SH_NEST_INDQ	0x01
# define SH_NEST_M		0x0f
// TODO: max is 7

/**
 * bin_ht:		hash-table of bins <name, path>
 * bin_nl:		list of bin names
 */
typedef struct	s_sh
{
	uint8_t		mode;
	uint8_t		nest;
	t_jcon		*jc;
	pid_t		pgid;
	t_termios	tmodes;
	int			term_std;
	t_term		term;
	int			inter;
	int 		stdi;
	int 		stdo;
	t_hset		*bin_ht;
	t_dastr		*bin_nl;
	t_table		*var;
	int 		*sub_pipe;
	t_dstr		*sub_out;
	uint8_t		exit;
}				t_sh;

t_sh 			*sh_sh(void);
int 			sh_sh_init(t_sh **sh, char **envp, int mode);
t_sh 			*sh_sh_clone(t_sh *sh, int mode);
int 			sh_sh_new(t_sh **sh);
int 			sh_sh_free(t_sh **sh);

#endif
