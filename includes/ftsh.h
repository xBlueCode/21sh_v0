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
//# include "sh_jobc.h"
//# include "sh_lex.h"
# include "sh_glob.h"
# include "sh_utils.h"
# include "sh_alias.h"

# define DF0 ft_dprintf(2, "%s\n", __FUNCTION__);

# define TEST_LEAKS 0

# define EXIT -2

# define CFPUTSTR(c, str, fd) (ft_dprintf(fd, "%s%s%s", c, str, T_END))

int			sh_script_run(t_sh *sh, char *script);

#endif
