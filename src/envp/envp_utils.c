#include "minishell.h"

void	print_envp(char **envp, char *header)
{
	int i = 0;
	printf("************ %s : ***************\n", header);
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
	printf("************ Line count (i) : %d ***************\n\n", i);
}

void	envp_utils_test(t_mnshl *vars)
{
	print_envp(vars->envp, "AT BEGINNING");
	printf("_ : %s\n", envp_get_value_line(vars, "_"));
	printf("ITER : %s\n", envp_get_value_line(vars, "ITER"));
	printf("HOMEBREW : %s\n", envp_get_value_line(vars, "HOMEBREW"));
	printf("HOMEBREW_CACHE : %s\n", envp_get_value_line(vars, "HOMEBREW_CACHE"));
	printf("USER : %s\n", envp_get_value_line(vars, "USER"));
	printf("USER : %s\n", envp_get_value_line(vars, "USER"));
	envp_remove_line(vars, "ITER");
	envp_remove_line(vars, "_");
	envp_remove_line(vars, "USER");
	envp_remove_line(vars, "HOMEBREW");
	print_envp(vars->envp, "AFTER DELETION");
}

/* _____________________________________________________________________________________________*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;

	if (*needle == '\0')
		return ((char *)haystack);
	len_needle = ft_strlen(needle);
	while (*haystack && len-- >= len_needle)
	{
		if (*haystack == *needle && !ft_strncmp(haystack, needle, len_needle))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}


int		is_name_in_line(char *envline, char *name)
{
	int	len;

	len = ft_strlen(name);
	if (!ft_strncmp(envline, name, len) && envline[len] == '=')
	{
		return (1);
	}
	return (0);
}

int		is_name_in_envp(char **envp, char *name)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (is_name_in_line(envp[i], name))
			return (i);
		i++;
	}
	return (-1);
}

char	*build_envp_line(char *name, char *value)
{
	char *line;

	line = ft_strjoin(name, "=");
	line = ft_strjoin(line, value);

	return (line);
}

/* _____________________________________________________________________________________________*/

/* Remove line from vars.envp
 *
 *	Arguments : 
 *		{t_mnshl}	{*vars}	: pointer to main struct of the program
 *		{char}		{*name} : name of environnement variable to remove.
 *
 *	Returns : 
 *		-- NOTHING --
 */
// TODO check is case sensitive
void envp_remove_line(t_mnshl *vars, char *name)
{
	int i;
	int j;
	char **n_envp;
	
	if (is_name_in_envp(vars->envp, name) >= 0)
	{
		n_envp = malloc(sizeof(char *) * (ft_strtablen(vars->envp) - 1));
		if (!n_envp)
			return ;
		i = 0;
		j = 0;
		while (vars->envp[i])
		{
			if (!is_name_in_line(vars->envp[i], name))
			{
				n_envp[j] = vars->envp[i];
				i++;
				j++;
			}
			else
			{
				i++;
			}
		}
		ft_freetabstr(&vars->envp);
		vars->envp = n_envp;
	}
}

/* Set line in envp from main structure of program. If not exists the
 * environement variables is create.
 *
 *	Arguments : 
 *		{t_mnshl *}	{vars}	: pointer to main struct of the program
 *		{char *}	{*name} : name of environnement variable to set.
 *
 *	Returns : 
 *		-- NOTHING --
 */
// TODO check is case sensitive
void envp_set_line(t_mnshl *vars, char *name, char *value)
{
	int		i;
	char	*n_line;
	char 	**n_envp;

	n_line = build_envp_line(name, value);
	i = is_name_in_envp(vars->envp, name);
	if (i >= 0)
	{
		free(vars->envp[i]);
		vars->envp[i] = n_line;
	}
	if (i < 0)
	{
		i = 0;
		n_envp = malloc(sizeof(char *) * (ft_strtablen(vars->envp) + 2));
		if (!n_envp)
			return ;
		while (vars->envp[i])
		{
			n_envp[i] = vars->envp[i];
			i++;
		}
		n_envp[i++] = n_line;
		n_envp[i] = "";
		ft_freetabstr(vars->envp);
		vars->envp = n_envp;
	}
}

/* Set line in envp from main structure of program. If not exists the
 * environement variables is create.
 *
 *	Arguments : 
 *		{t_mnshl *}	{vars}	: pointer to main struct of the program
 *		{char *}	{*name} : name of environnement variable to set.
 *
 *	Returns : 
 *		{char *} : pointeur to the value start in vars.envp
 */
// [REFLEXION : ON POURRAIT RETOURNER LE POINTEUR APRES LE =,
// ce qui eviterais de devoir faire un free. Etant une string ca termine par '\0']
// TODO check is case sensitive
char *envp_get_value_line(t_mnshl *vars, char *name)
{
	char 	*ret;
	int 	i;

	ret = NULL;
	i = 0;
	while (vars->envp[i])
	{
		if (is_name_in_line(vars->envp[i], name) >= 0)
		{	
			ret = &vars->envp[i][ft_strlen(name) + 1];
			return (ret);
		}
		i++;
	}
	return (ret);
}

