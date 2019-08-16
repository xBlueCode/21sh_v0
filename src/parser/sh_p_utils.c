#include "ftsh.h"

extern int	g_btreeapp_lev;

int		sh_p_lookshift(t_parser *p)
{
	/*
	if (!p || !p->tlast)
		PRET(0)
	p->tlook = p->tlast->next;
	PRET(1)
	 */
	(void)p;
	return (0);
}

void 	test_sh_p_astapp(t_btree *root)
{
	int i;

	if (!root)
		return;

	i = -1;
	while (++i < g_btreeapp_lev)
		ft_printf("%s |"T_END, i % 2 ? C_GRN : C_RED);
	ft_printf("- GR(%03d): ", root->op);
	//ft_printf("%*c GR(%03d): ", 2 * g_btreeapp_lev, '-', root->op);
	ft_printf(C_CYN"  L (%03d) "T_END, root->left ? root->left->op : 0);
	ft_putstr(" | ");
	ft_printf(C_MGN" R (%03d)"T_END, root->right ? root->right->op : 0);
	if (root->data && ft_printf(" | "))
		DPTOKPUT(((t_token*)root->data))
	else
		ft_putendl("");
	//ft_printf(C_CYN"\n  %*c (%d)"T_END, g_btreeapp_lev, 'L',root->left ? root->left->op : 0);
	//ft_printf(C_MGN"\n  %*c (%d)"T_END, g_btreeapp_lev, 'R',root->right ? root->right->op : 0);
}

int		sh_p_match(t_parser *p, t_btree **ast, int target)
{
//	t_btree *cast;
	t_token *token;

	//SHP_CAST_INIT(target);
	DPM0
	if (!p->tlook || !(token = (t_token*)p->tlook->content))
		PMRET(0);
	if (token->t == TSTOK)
	{
		if (!sh_tok_distinct(p->tlook->content, target))
			PMRET(0)
	}
	else if (((t_token*)p->tlook->content)->t != target)
		PMRET(0)
	if (ast && *ast)
	{
		//(*ast)->data = ft_strndup(p->tlook->content, sizeof(t_token));
		(*ast)->data = p->tlook->content;
		(*ast)->dsize = sizeof(t_token);
	}
	DPM1
	p->tlook = p->tlook->next;
	PMRET(1)
	//return (1);
}


/*
int		sh_p_match(t_parser *p, void **data, int toktype)
{
//	t_btree *cast;

	//SHP_CAST_INIT(toktype);
	DPM0
	if (!p->tlook)
	PMRET(0)
	if (toktype == TSTOK_WORD) // TODO: Just for debugging
		toktype = TSTOK;
	if (((t_token*)p->tlook->content)->t != toktype)
	PMRET(0)
	//cast->data = ft_strndup(p->tlook->content, p->tlook->content_size);
	if (data)
	{
		*data = ft_strndup(p->tlook->content, p->tlook->content_size);
//		*data->dsize = p->tlook->content_size;
	}
	DPM1
	p->tlook = p->tlook->next;
	PMRET(1)
	//return (1);
}
*/