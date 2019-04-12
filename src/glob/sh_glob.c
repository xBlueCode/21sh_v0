int     sh_glob(char *pat)
{
    char	**cond;
	ssize_t	shi;
	ssize_t	i;
	char	*wd;

	i = 0;
	if (*pat == '/' && ++i)
		wd = ft_strdup("/");
	else
		wd = "."; // Get working directory
	while ((shi = ft_strichr(pat + i, '/')) > -1)
	{
		cond = sh_glob_scandir(wd);
		matches = sh_glob_match
	}
	//cond = sh_glob_scandir();
	/*
    if (!ft_strchr(pat, '/'))
        cond = sh_glob_scandir(_get_pwd(), ALL);
    else if (!ft_strncmp(pat, "./", 2))
        cond = sh_glob_scandir(_get_pwd(), EXE);
    else if (*pat == '/')
    	return (0);
		*/
}
