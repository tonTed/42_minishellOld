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
	printf("************ Line count (i) : %d ***************\n", i);
}

void	envp_utils_test(t_mnshl *vars)
{
	printf("_ : %s\n", envp_get_value_line(vars, "_"));
	printf("ITER : %s\n", envp_get_value_line(vars, "ITER"));
	printf("HOMEBREW : %s\n", envp_get_value_line(vars, "HOMEBREW"));
	printf("HOMEBREW_CACHE : %s\n", envp_get_value_line(vars, "HOMEBREW_CACHE"));
	printf("USER : %s\n", envp_get_value_line(vars, "USER"));
}

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
	int deleted;
	deleted = 0;
	i = 0;
	while (vars->envp[i])
	{
		if (!ft_strncmp(vars->envp[i], name, ft_strlen(name)) && !deleted)
		{	
			if (vars->envp[i][ft_strlen(name)] == '=')
				deleted = 1;
		}
		if (deleted)
		{
			if (vars->envp[i + 1])
				vars->envp[i] = ft_strdup(vars->envp[i + 1]);
			else 
				vars->envp[i] = NULL;
		}
		i++;
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
	//if no exists -> append
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

	i = 0;
	ret = NULL;
	while (vars->envp[i])
	{
		if (!ft_strncmp(vars->envp[i], name, ft_strlen(name)))
		{	
			if (vars->envp[i][ft_strlen(name)] == '=')
			{
				ret = &vars->envp[i][ft_strlen(name) + 1];
				break ;
			}
		}
		i++;
	}
	return (ret);
}

