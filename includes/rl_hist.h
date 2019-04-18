// header

#ifndef RL_HIST_H
#define RL_HIST_H

#include "libft.h"

# define HIS_FILENAME ".rl_history"

typedef struct	e_hist
{
	char 		*filename;
	t_dastr		*ent;
	t_dastr		*back;
	int 		off;
	int 		cur;
}				t_hist;


int 			rl_hist_init(char *filename);
int				rl_hist_upload(void);
int				rl_hist_save(void);
int				rl_hist_read(int fd);
int				rl_hist_write(int fd);
int				rl_hist_parse(char *str, int num);
int 			rl_hist_add(char *line);
int				rl_hist_print(void);

#endif
