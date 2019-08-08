#include "ftsh.h"

int		sh_p_lookshift(t_parser *p)
{
	if (!p || !p->tlast)
		PRET(0)
	p->tlook = p->tlast->next;
	PRET(1)
}

int		sh_p_match(t_parser *p, t_btree **ast, int toktype)
{
	(void)ast;
	DPM0
	if (!p->tlook)
		PRET(0)
	if (toktype == TSTOK_WORD) // TODO: Just for debugging
		toktype = TSTOK;
	if (((t_token*)p->tlook->content)->t != toktype)
		PRET(0)
	//return (sh_p_lookshift(p));
	DPM1
	p->tlook = p->tlook->next;
	PRET(1)
	//return (1);
}
