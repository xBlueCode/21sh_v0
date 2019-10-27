/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cell.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:35:20 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 12:35:21 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CELL_H
# define FT_CELL_H

typedef struct	s_cell
{
	int x;
	int y;
	int v;
}				t_cell;

t_cell			ft_cell(int x, int y, int v);
t_cell			ft_cell_mid(t_cell c1, t_cell c2);

#endif
