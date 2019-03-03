/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:32:18 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/03 14:22:57 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum		e_token_state
{
	TSG,
	TSL,
	TSE,
	TSA,
	TSO,
	TSM,
	TSN,
	TSD,
	TSSC,
	TSPL,
	TSPR,
	TSBL,
	TSBR,
	TSCBL,
	TSCBR,
	TSNL,
	TSSQ,
	TSDQ,
	TSSH,
	TSBSH,
	TSAES,

	TSG2,
	TSG_E,
	TSG_A,
	TSG_O,
		
	TSL_G,
	TSL2,
	TSL2_M,
	TSG_E,
	TSG_A,
	TSG_O,

	TSA_G,
	TSA2,

	TSO2,

	TSMp,

	TSD_PL,
	TSD_PL2,
	TSD_CBL,

	TSSC2,

	TSPL2,
}					t_token_state;

typedef struct		s_token
{
	int		ts;
	char	*xme;
}					t_token;

#endif
