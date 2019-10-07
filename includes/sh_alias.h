/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_alias.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:33:52 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:33:53 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_ALIAS_H
#define SH_ALIAS_H

#include <libft.h>

# define SH_ALS_HTSIZE 48


t_hset		*sh_als(void);
int 		sh_als_init(void);

int 		sh_als_add(t_hset *als, char *key, char *val);
int 		sh_als_rem(t_hset *als, char *key);

int 		sh_als_print(t_hset*);
void 		sh_als_print_ent(t_list*);

#endif //FTSH_SH_ALIAS_H
