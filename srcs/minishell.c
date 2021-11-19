/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:21:19 by oscarlo           #+#    #+#             */
/*   Updated: 2021/11/19 16:09:27 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	make_cmd(char *cmd, t_list **all_cmds, char **envp)
{
	char	**separate;
	t_list	*index;

	separate = ft_special_split(cmd, ' ');
	if (!separate)
		return (1);
	ft_getenv_var(separate, envp, 0, 0);
	clean_n(separate, 1, 0);
	clean_quotes(separate, 0, 0);
	index = ft_builtins(separate, all_cmds);
	if (!index)
		index = ft_lst_push(all_cmds, NULL, separate);
	if (check_redirections(index) == -42)
		return (1);
	return (0);
}

int	parse_second(char *str, t_list **all_cmds, char ***envp)
{
	char	**separate;
	int		i;

	separate = ft_special_split(str, '|');
	if (!separate)
		return (0);
	i = 0;
	while (separate[i])
	{
		if (!separate [i][0])
			return (0);
		if (make_cmd(separate[i], all_cmds, *envp))
			return (0);
		free(separate[i]);
		i++;
	}
	free(separate);
	ft_pipe(*all_cmds, envp);
	return (42);
}

int	parse_first(char *str, t_list **all_cmds, char ***envp)
{
	char	**separate;
	int		i;

	separate = ft_special_split(str, 127);
	if (!separate)
		return (0);
	i = 0;
	while (separate[i])
	{
		if (!parse_second(separate[i], all_cmds, envp))
			return (0);
		free(separate[i]);
		ft_lst_free(*all_cmds);
		i++;
	}
	free(separate);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	char				*str;
	char				**envp_cpy;
	t_list				*all_cmds;

	envp_cpy = ft_envpdup(envp);
	ft_sig_manage(1);
	all_cmds = NULL;
	if (ac >= 3 && !ft_strncmp(av[1], "-c", 3))
		parse_first(av[2], &all_cmds, &envp_cpy);
	while (!all_cmds)
	{
		str = readline("==> ");
		add_history(str);
		if (!str)
		{
			write(STDOUT_FILENO, "exit\n", 5);
			return (1);
		}
		if (parse_first(str, &all_cmds, &envp_cpy))
			all_cmds = NULL;
		free(str);
	}
	ft_forget_env(envp_cpy);
	return (0);
}
