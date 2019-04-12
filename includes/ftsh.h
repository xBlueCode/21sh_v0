/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 18:50:44 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/27 16:47:08 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTSH_H
# define FTSH_H

#include "libft.h"

# include <sys/ioctl.h>
# include <termcap.h>
# include <termios.h>
# include <term.h>

# include "sh_prompt.h"
# include "sh_term.h"
# include "ft_rl.h"
# include "sh_lex.h"
# include "sh_utils.h"

# define TEST_LEAKS 0

# define EXIT -2

# define CFPUTSTR(c, str, fd) (ft_dprintf(fd, "%s%s%s", c, str, T_END))

#endif
