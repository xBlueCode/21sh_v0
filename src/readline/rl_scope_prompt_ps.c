#include "libft.h"
#include "ftsh.h"

extern t_rl g_rl;

int 		rl_scope_prompt_ps_u(t_dstr *prompt, int i)
{
	if (ft_strncmp(prompt->str + i, "\\u", 2))
		return (KO);
	ft_dstrdel_n(prompt, i, 2);
	ft_dstrins_str(prompt, i, sh_var_getval(sh_sh()->var, "USER"));
	return (OK);
}

int 		rl_scope_prompt_ps_w(t_dstr *prompt, int i)
{
	//char *pwd;

	if (ft_strncmp(prompt->str + i, "\\w", 2))
		return (KO);
	ft_dstrdel_n(prompt, i, 2);
	ft_dstrins_str(prompt, i, sh_var_getval(sh_sh()->var, "PWD"));
	return (OK);
}

int 		rl_scope_prompt_ps_h(t_dstr *prompt, int i)
{
	char	hostname[512];

	if (ft_strncmp(prompt->str + i, "\\h", 2))
		return (KO);
	ft_dstrdel_n(prompt, i, 2);
	if (gethostname(hostname, 512))
		return (KO);
	ft_dstrins_str(prompt, i, hostname);
	return (OK);
}
