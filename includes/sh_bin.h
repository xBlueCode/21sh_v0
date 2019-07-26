#ifndef SH_BIN_H
#define SH_BIN_H

# include "libft.h"

# define SH_BIN_HTSIZE 2048

t_hset 	*sh_bin(void);
t_dastr	*sh_bin_names(void);
t_hset 	**sh_bin_ptr(void);
int 	sh_bin_init(t_hset **phtbin);
int 	sh_bin_update(t_hset *phtbin, char *paths);

char	*sh_bin_getpath(t_hset *htbin, char *bin);

int		sh_bin_add_abs(t_hset *htbin, char *binpath);

int		sh_bin_filter(const struct dirent *);

#endif
