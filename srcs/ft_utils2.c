#include "../libft/includes/libft.h"

char    *replace_path(char *path, char **env)
{
    char **tab;
    char *tmp;
    int i;

    tab = ft_strsplit(path, '/');
    i = 0;
    while(tab[i])
    {
        if(tab[i][0] == '$')
        {
            tmp = getvalue(tab[i], env);
            ft_strdel(&tab[i]);
            tab[i] = ft_strdup(tmp);
        }
        i++;   
    }
    return(ft_newpath(tab));

}

char    *getvalue(char *var, char **env)
{   
    char *tmp;
    char *chr;
    int i;
    int j;

    tmp = ft_strstr(var, &var[1]);
    i = 0;
    while(env[i])
    {
        if (ft_strncmp(env[i], tmp, ft_strlen(tmp)) == 0)
        {   
            chr = ft_strchr(env[i], '=');
            j = (int)(chr - env[i]);
            tmp = ft_strstr(env[i], &env[i][j + 1]);
        }
        i++;
    }
    return(tmp);
}

char *ft_newpath(char **tab)
{
	int i;
	char *tmp;
	
	i = 0;
	tmp = "/";
	while(*tab[i] != '\0')
	{	
		tmp = ft_strjoin(tmp, tab[i]);
		tmp = ft_strjoin(tmp, "/");
		i++;
	}
	return tmp;
}