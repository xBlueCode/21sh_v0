#include "libft.h"
#include "sh_alias.h"

t_hset		*g_als;

t_hset		*sh_als(void)
{
	return (g_als);
}

int 		sh_als_init(void)
{

	g_als = ft_hset_init(SH_ALS_HTSIZE,
		ft_htab_hcode_str, ft_htab_equals_str, ft_htab_free_ent_str);
	return (OK);
}

int 		sh_als_add(t_hset *als, char *key, char *val)
{
	t_htabent	ent;

	if (!als || !key || !val)
		return (KO);
	ent = (t_htabent){
		.key = key, .ksize = ft_strlenz(key) + 1,
		.val = val, .vsize = ft_strlenz(val) + 1};
	return (ft_htab_put(als, &ent));
}

int 		sh_als_rem(t_hset *als, char *key)
{
	if (!als || !key)
		return (KO);
	return (ft_htab_rem(als, key, ft_strlen(key) + 1));
}

int 		sh_als_print(t_hset *als)
{
	int i;

	i = -1;
	while (++i < als->max)
		ft_lstiter(als->arr[i], &sh_als_print_ent);
	return (OK);
}

void 		sh_als_print_ent(t_list *entlst)
{
	ft_putstr("Alias: ");
	ft_putstr((char*)((t_htabent*)entlst->content)->key);
	ft_putchar('=');
	ft_putstr((char*)((t_htabent*)entlst->content)->val);
}
