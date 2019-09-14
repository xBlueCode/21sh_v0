#ifndef FTSH_H
# define FTSH_H

#include "libft.h"

# include <sys/ioctl.h>
# include <termcap.h>
# include <termios.h>
# include <term.h>

# include "sh_prompt.h"
# include "sh_var.h"
# include "sh_bin.h"
# include "sh_term.h"
# include "ft_rl.h"
//# include "rl_hist.h"
# include "sh_parser.h"
# include "sh_jobc.h"
# include "sh_sh.h"
# include "sh_exec.h"
# include "sh_expan.h"
//# include "sh_jobc.h"
//# include "sh_lex.h"
# include "sh_glob.h"
# include "sh_utils.h"
# include "sh_alias.h"
# include "sh_builtin.h"

//# define DF0 ft_dprintf(2, C_YLW"%s\n"T_END, __FUNCTION__);
# define DF0

# define D_INSTWAIT(inst, t) {inst; sleep(t);}

# define DF_PFWAIT(m, t) D_INSTWAIT(ft_printf("%s: %s\n", __FUNCTION__, m), t)

# define TEST_LEAKS 0

# define EXIT -2

# define CFPUTSTR(c, str, fd) (ft_dprintf(fd, "%s%s%s", c, str, T_END))

# define SH_PATHNAME_MAX 1023

# define SH_FILENAME_MAX 255

int			sh_script_run(t_sh *sh, char *script);

#endif
