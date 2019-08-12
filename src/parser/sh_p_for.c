#include "ftsh.h"

int				sh_p_for_clause(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_FOR_CLAUSE)
	if (!sh_p_match(p, NULL, TSRW_FOR))
		PRET(0)
	else if (!sh_p_match(p, &cast, SH_GR_NAME))
		PRET(0);
	sh_p_lbreak(p, NULL);
	sh_p_match(p, NULL, TSRW_IN);
	sh_p_wordlist(p, SHP_CAST_L);
	sh_p_seq_sep(p, NULL);
	if (!sh_p_do_group(p, SHP_CAST_R))
		PRET(0);
	PRET(1)
}

//int				sh_p_name(t_parser *p, t_btree **ast);
//int				sh_p_in(t_parser *p, t_btree **ast);

int				sh_p_wordlist(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_WORDLIST)
	if (!sh_p_match(p, &cast, TSTOK_WORD))
		PRET(0);
	if (!sh_p_wordlist_sub(p, SHP_CAST_R))
		PRET(0);
	PRET(1)
}

int				sh_p_wordlist_sub(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_WORDLIST_SUB)
	if (!sh_p_match(p, &cast, TSTOK_WORD))
		PRET(1);
	if (!sh_p_wordlist_sub(p, SHP_CAST_R))
		PRET(0);
	PRET(1);
}
