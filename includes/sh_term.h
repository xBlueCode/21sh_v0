/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 11:28:23 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/17 12:38:17 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_TERM_H
# define SH_TERM_H

# define TER_DEF "xterm-256color"

typedef struct	s_term
{
	int					winw;
	int					winh;
	int					prompt_len;
	struct termios		tconfig_def;
}				t_term;

int				sh_termconfig_init(t_term *term);
int				sh_termconfig_reset(t_term *term);

#endif
