/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:37:36 by tonted            #+#    #+#             */
/*   Updated: 2022/04/20 00:51:54 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include "../libraries/libft/include/libft.h"
# include "../libraries/readline/includes/readline.h"
# include "../libraries/readline/includes/history.h"

# define PROMPT "cryptoShell> "
# define DQ '\"'
# define Q '\''
# define PIPE '|'
# define WHOAMI printf(GRN"Function "BMAG"%s"GRN" ran "BGRN"SUCCESSFULLY\n"RESET, __func__);

/*
	cmd: 		block command in string
	cmd_split:	splited block command
	flag:
		0x1 -> here_doc
*/
typedef struct s_heredoc
{
    int     index;
    char    *eof;
}   t_heredoc;

typedef struct s_tab_cmds
{
	char		*cmd;           // Full block of command
	char		**cmd_split;	//cmd splitted with split_custom()
	char		flag;   		//Bitwise flags (See *)
	t_heredoc	*tab_heredoc;	//Index of command with heredoc

}			t_tab_cmds;

typedef struct s_mnshl
{
	/* ENV */
	char 	**envp;
	int		last_error;
	/* data */
    t_tab_cmds *cmds_tab;
}			t_mnshl;

// prompt.c //
void	prompt_DUMMY(void);

// ft_execute_line.c //
void	ft_execute_line(char *line);

// init_vars.c //
void	init_vars(t_mnshl *vars, char **envp);

// heredoc.c //
void    open_heredoc(t_mnshl *vars)





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