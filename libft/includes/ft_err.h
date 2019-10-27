/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:31:55 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 12:31:56 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERR_H
# define FT_ERR_H

# define FT_ERR_RETMSG(ret, msg) {ft_putendl(msg); return (ret);}

# define FT_STDE_M C_RED"%s\n"T_END
# define FT_STDE_RET(ret, msg) {ft_dprintf(2, FT_STDE_M, msg); return (ret);}
# define FT_STDEPF(fmt, msg) {ft_dprintf(2, fmt, msg);}
# define FT_INST_RET(r, inst) {inst; return (r);}

#endif
