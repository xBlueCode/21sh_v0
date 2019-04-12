/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ctrl_save.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:20:56 by abbesbes          #+#    #+#             */
/*   Updated: 2019/04/02 16:51:02 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern t_rl		g_rl;

int				rl_ctrl_save_before(int c)
{
	t_dstr	*dline;
	char	*str;

	(void)c;
	if (!g_rl.cc)
	{
		ft_putchar(0x07);
		return (1);
	}
	dline = g_rl.txt->a[g_rl.cl];
	str = ft_strndup(dline->str, g_rl.cc);
	if (g_rl.reg->max < ++g_rl.regi)
		ft_dastrext_x2(g_rl.reg);
	g_rl.reg->a[g_rl.regi] = ft_dstrnew_str_free(&str);
	return (0);
}

int				rl_ctrl_save_after(int c)
{
	t_dstr	*dline;
	char	*str;

	(void)c;
	dline = g_rl.txt->a[g_rl.cl];
	if (!dline->str[g_rl.cc])
	{
		ft_putchar(0x07);
		return (1);
	}
	str = ft_strdup(dline->str + g_rl.cc);
	if (g_rl.reg->max < ++g_rl.regi)
		ft_dastrext_x2(g_rl.reg);
	g_rl.reg->a[g_rl.regi] = ft_dstrnew_str_free(&str);
	return (0);
}

int				rl_ctrl_save_w_before(int c)
{
	t_dstr	*dline;
	ssize_t	i;
	char	*str;

	(void)c;
	i = g_rl.cc;
	dline = g_rl.txt->a[g_rl.cl];
	if (!g_rl.cc || ft_isspace(dline->str[i]) || ft_isspace(dline->str[i - 1]))
	{
		ft_putchar(0x07);
		return (1);
	}
	while (i > -1 && !ft_isspace(dline->str[i]))
		i--;
	i++;
	str = ft_strndup(dline->str + i, g_rl.cc - i);
	if (g_rl.reg->max < ++g_rl.regi)
		ft_dastrext_x2(g_rl.reg);
	g_rl.reg->a[g_rl.regi] = ft_dstrnew_str_free(&str);
	return (0);
}

int				rl_ctrl_save_w_after(int c)
{
	t_dstr	*dline;
	ssize_t	i;
	char	*str;

	(void)c;
	i = g_rl.cc;
	dline = g_rl.txt->a[g_rl.cl];
	if (!dline->str[i] || ft_isspace(dline->str[i]))
	{
		ft_putchar(0x07);
		return (1);
	}
	while (dline->str[i] && !ft_isspace(dline->str[i]))
		i++;
	str = ft_strndup(dline->str + g_rl.cc, i - g_rl.cc);
	if (g_rl.reg->max < ++g_rl.regi + 1)
		ft_dastrext_x2(g_rl.reg);
	g_rl.reg->a[g_rl.regi] = ft_dstrnew_str_free(&str);
	return (0);
}
