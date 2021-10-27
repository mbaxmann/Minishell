#include "../include/minishell.h"

void	shift_fd(char *file)
{
	(void) file;
	return ;
}

int make_cmd(char *cmd, t_list **all_cmds)
{
	char **separate;

	//check_redirect(*all_cmds, cmd + depla);
	separate = ft_split(cmd, ' ');
	if (!strncmp("echo", separate[0], 5))
		ft_lst_push_front(all_cmds, &ft_echo, separate);
	else if (!strncmp("cd", separate[0], 3))
		ft_lst_push_front(all_cmds, &ft_cd, separate);
	else if (!strncmp("exit", separate[0], 6))
		exit(ft_atoi(separate[1]));
	else
	{
		ft_lst_push_front(all_cmds, NULL, separate);
		ft_putstr_fd("minishell: ", (*all_cmds)->fd2, 0);
		ft_putstr_fd((*all_cmds)->arg[0], (*all_cmds)->fd2, 0);
		ft_putstr_fd(": command not found\n", (*all_cmds)->fd2, 0);
		return (1);
	}
	return (0);
}

int parse_cmds(char *str, t_list **all_cmds, int iter)
{
	char	**separate;
	int		i;

	if (iter == 0)
	{
		separate = ft_split(str, ';');
		i = 0;
		while (separate[i] && iter < 1)
		{
			parse_cmds(separate[i], all_cmds, iter + 1);
			free(separate[i]);
			ft_lst_free(*all_cmds);
			i++;
		}
	}
	if (iter == 1)
	{
		separate = ft_split(str, '|');
		i = 0;
		while (separate[i])
		{
			if (make_cmd(separate[i], all_cmds))
				return (1);
			free(separate[i]);
			i++;
		}
	}
	free (separate);
	if (iter == 1 && i > 1)
		ft_pipe(*all_cmds);
	else if (iter == 1)
		(*all_cmds)->funct((*all_cmds)->arg);
	return (42);
}


int	main()
{
	char	*str;
	t_list	*all_cmds;

	while (1)
	{
		all_cmds = NULL;
		str = readline("==> ");
		add_history(str);
		//replace_dollars(str);
		if (!str)
			return (1);
		if (!parse_cmds(str, &all_cmds, 0))
		{
			free(str);
			return (1);
		}
		free(str);
	}
	return (0);
}
