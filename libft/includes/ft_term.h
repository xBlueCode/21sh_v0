/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 19:37:03 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/27 19:43:52 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERM_H
# define FT_TERM_H

# include <term.h>

# define KCA 0x01
# define KCB 0x02
# define KCC 0x03
# define KCD 0x04
# define KCE 0x05
# define KCF 0x06
# define KCG 0x07
# define KCH 0x08
# define KCI 0x09
# define KCK 0x0b
# define KCL 0x0c
# define KCN 0x0e
# define KCP 0x10
# define KCR 0x12
# define KCT 0x14
# define KCU 0x15
# define KCV 0x16
# define KCW 0x17
# define KCX 0x18

# define KMA 0xa5c3
# define KMB 0xab88e2
# define KMC 0xa7c3
# define KMD 0x8288e2
# define KMF 0x92c6

# define KESC 0x1B
# define KSPC 0x20
# define KRET 0xA
# define KBSPC 0x7F
# define KUP 0x415B1B
# define KDOWN 0x425B1B
# define KRIGHT 0x435B1B
# define KLEFT 0x445B1B
# define KDEL 0x7E335B1B

# define T_BLD	"\033[1m"
# define T_UND	"\033[4m"
# define T_BLK  "\033[5m"
# define T_REV	"\033[7m"
# define T_END  "\033[0m"

# define C_BLK "\033[90m"
# define C_RED  "\033[91m"
# define C_GRN  "\033[92m"
# define C_YLW  "\033[93m"
# define C_BLU  "\033[94m"
# define C_MGN  "\033[95m"
# define C_CYN  "\033[96m"
# define C_WHT  "\033[97m"

# define CB_BLK "\033[100m"
# define CB_RED  "\033[101m"
# define CB_GRN  "\033[102m"
# define CB_YLW  "\033[103m"
# define CB_BLU  "\033[104m"
# define CB_MGN  "\033[105m"
# define CB_CYN  "\033[106m"
# define CB_WHT  "\033[107m"

typedef struct termios	t_termios;

#endif
