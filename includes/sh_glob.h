#ifndef SH_GLOB_H
# define SH_GLOB_H

int		rl_glob_indir(char *base, char *spath, char *pat, t_dastr *res);
int		rl_glob_indir_lin(char *base, char *spath, char *pat, t_dastr *res);

t_list	*sh_glob_scandir(char *base, char *spath);

int     sh_glob_match(char *str, char *pat);
int     sh_glob_match_range(int c, char *ran);
//int     sh_glob_match(char *str, char *pat);

#endif
