#include "minishell.h"

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
 *		{char *} : value inside de environement variable.
 */
// REFLEXION : ON POURRAIT RETOURNER LE POINTEUR APRES LE =,
// ce qui eviterais de devoir faire un free. Etant une string ca termine par '\0'

// TODO check is case sensitive
char *envp_get_value_line(t_mnshl *vars, char *name)
{
	char *ret;

	return (ret);
}

