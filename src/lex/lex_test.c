/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:16:31 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/04 20:42:22 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

int		main(void)
{
	//ft_printf("Testing lex ... !\n");
	if (!(x_tokenize(">< \"Hello \\\"'Worl'd\">>")))
		ft_printf("NULL TKLIST !!!\n");
	return (0);
}
