/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:37:36 by tonted            #+#    #+#             */
/*   Updated: 2022/05/31 13:47:05 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <signal.h>
# include "../libraries/libft/include/libft.h"
# include "../libraries/readline/includes/readline.h"
# include "../libraries/readline/includes/history.h"

# define PROMPT "cryptoShell> "
# define DQ '\"'
# define Q '\''
# define PIPE '|'


/* TODO explain each status
** 0: all is good!
*/
extern int g_status;

//# define WHOAMI ;
# define WHOAMI printf(GRN"Function "BMAG"%s"GRN" ran "BGRN"SUCCESSFULLY\n"RESET, __func__);

/*
	cmd: 		block command in string
	cmd_split:	splited block command
	flag:
		0x1 -> here_doc
*/
typedef struct s_heredoc
{
    int     index_cmd; 			// index de cmd_block
    char    *eof;
}   t_heredoc;

typedef	char* str;

// TODO comments
typedef struct s_cmd_block
{
	char		**cmd_split;	//cmd splitted with split_custom()
	char		*cmd;           // Full block of command
	char		*filein;
	char		flag; 			//Bitwise flags (See *)
}			t_cmd_block;

// TODO comments
typedef struct s_mnshl
{
	char 			**envp;
	int				last_errno;
    t_cmd_block 	*cmds_tab;
	uint32_t		cmds_count;
	t_heredoc		*tab_heredoc;	//Index of command with heredoc
	uint32_t		heredoc_count;
}			t_mnshl;

/* ___________________________ FUNCTION PROTOTYPE ____________________________ */

// prompt.c //
char	*prompt_DUMMY();

// ft_execute_line.c //
int	parse_line(t_mnshl *vars, char *line);

// init_vars.c //
void	init_vars(t_mnshl *vars, char **envp);
void	free_exit(t_mnshl *vars);

// Builtins //
void	ft_export(char **args, char **envp, int fd_out);
void	ft_echo(char **args, char **env, int fd_out);
void	ft_pwd(char **args, char **env, int fd_out);
void	ft_unset(char **args, char **env, int fd_out);

// envp_utils.c //
void	envp_remove_line(char **envp, char *name);
char	*envp_get_value_line(char **envp, char *name);
void	envp_set_line(char **envp, char *name, char *value);

// heredoc.c //
int heredoc(t_mnshl *vars);

// put_utils.c //
void	put_envp(char **envp);

int	execute_all_blocks(t_mnshl *vars);
int	execute(t_mnshl *vars);

/* Remove line from vars.envp
 *
 *		Arguments : 
 *			{TYPE} {ARG1 NAME} : 
 *			{TYPE} {ARG2 NAME} :
 *
 *		Returns : 
 *			{TYPE} {VAR NAME} : 
 */
int	clean_up(t_mnshl *vars, char *line);

/*
--- * ---
0x1  -> quote
		0x2  -> dquote
		0x4  -> quote_end
		0x8  -> dquote_end
		0x16 -> $ and quote closed then pas interpreter
		0x32 -> heredoc
		0x64 -> 
		0x128 ->  
---------
*/

int create_cmd_block(char *line, size_t len, t_mnshl *vars);

#endif