/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_hist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:33:49 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:33:51 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RL_HIST_H
# define RL_HIST_H

# include "libft.h"

# define RL_HIS_FILENAME ".rl_history"

typedef struct	s_hist
{
	char 		*filename;
	t_dastr		*ent;
	t_dastr		*back;
	int 		off;
	int 		cur;
}				t_hist;

int 			rl_hist_init(char *filename);
int 			rl_hist_free(void);
t_hist 			rl_hist_get(void);
int 			rl_hist_reset(void);
int				rl_hist_upload(void);
int				rl_hist_save(void);
int				rl_hist_read(int fd);
int				rl_hist_write(int fd);
int				rl_hist_parse(char *str, int num);
t_dastr			*rl_hist_get_txt(int cur);
int 			rl_hist_add(char *line);
int				rl_hist_print(void);

int				rl_hist_req_up(int c);
int				rl_hist_req_do(int c);
int 			rl_hist_req_cur(int cur);

#endif
