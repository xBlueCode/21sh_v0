/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_keymapper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:04:57 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/27 12:13:11 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../libft/includes/libft.h"
#include "../includes/ftsh.h"

int main(void)
{
	int c;

	sh_termconfig_init();
	while (!(c = 0) && read(0, &c, 1) && c != '\n')
		printf("%C\n", c);
	sh_termconfig_reset();
	return (0);
}
