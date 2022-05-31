#include "minishell.h"

void	put_t_heredoc(t_heredoc *tab_heredoc, uint32_t count)
{
	int i;
	printf(BYEL "\n~~~~~ start tab_heredoc [%u] ~~~~~\n" YEL, count);
	i = 0;
	while (i < count)
	{
		printf("heredoc %d: %s (eof)\n",
			tab_heredoc[i].index_cmd,
			tab_heredoc[i].eof);
	}
	printf(BYEL "\n~~~~~ end tab_heredoc ~~~~~\n" RESET);
}

void	put_t_cmd_block(t_cmd_block cmd_block)
{
}

void	put_envp(char **envp)
{
	int	i;

	i = 0;
	printf("************ Envp beginning : ***************\n");
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
	printf("************ Line count (i) : %d ***************\n\n", i);
}

void	put_cmds_tab(t_cmd_block *cmds_tab, uint32_t count)
{
	int i;

	printf(BGRN "\n----- start cmds_tab [%u] -----\n" GRN, count);
	i = 0;
	while (i < count)
	{
		printf("vars.cmd_split:\n");
		ft_puttabstr_fd(cmds_tab[i].cmd_split, 1);
		printf("cmd: %s\n", cmds_tab[i].cmd);
		printf("filein: %s\n", cmds_tab[i].filein);
		printf("flag: %c\n", cmds_tab[i].flag);
		i++;
	}
	printf(BGRN "\n----- end cmds_tab -----\n" RESET);
}

void	put_t_mnshl(t_mnshl vars)
{
	printf(BCYN "\n===== start mnshl =====\n" CYN);
	printf("vars.envp:\n");
	ft_puttabstr_fd(vars.envp, STDOUT_FILENO);
	printf("Last errno: %d\n", vars.last_errno);
	put_cmds_tab(vars.cmds_tab, vars.cmds_count);
	put_t_heredoc(vars.tab_heredoc, vars.heredoc_count);
	printf(BCYN "\n===== end mnshl =====\n" RESET);
}