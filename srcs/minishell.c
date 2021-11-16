/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:21:19 by oscarlo           #+#    #+#             */
/*   Updated: 2021/11/17 00:08:16 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	make_cmd(char *cmd, t_list **all_cmds, char **envp)
{
	char	**separate;
	int		return_value;
	t_list	*index;

	return_value = 0;
	separate = ft_special_split(cmd, ' ');
	ft_getenv_var(separate, envp);
	clean_quotes(separate);
	if (!ft_strncmp("echo", separate[0], 5))
		index = ft_lst_push(all_cmds, &ft_echo, separate);
	else if (!ft_strncmp("cd", separate[0], 3))
		index = ft_lst_push(all_cmds, &ft_cd, separate);
	else if (!ft_strncmp("pwd", separate[0], 4))
		index = ft_lst_push(all_cmds, &ft_pwd, separate);
	else if (!ft_strncmp("exit", separate[0], 6))
		exit(ft_atoi(separate[1]));
	else if (!ft_strncmp("env", separate[0], 4))
		index = ft_lst_push(all_cmds, &ft_env, separate);
	else if (!ft_strncmp("export", separate[0], 7))
		index = ft_lst_push(all_cmds, &ft_export, separate);
	else if (!ft_strncmp("unset", separate[0], 6))
		index = ft_lst_push(all_cmds, &ft_unset, separate);
	else if (!ft_strncmp("./", separate[0], 2))
		index = ft_lst_push(all_cmds, NULL, separate);
	else
	{
		index = ft_lst_push(all_cmds, NULL, separate);
		return_value = 1;
	}
	if (check_redirections(index) == -42)
		return (1);
	if (return_value)
	{
		ft_putstr_fd("minishell: ", 2, 0);
		ft_putstr_fd(separate[0], 2, 0);
		ft_putstr_fd(": command not found\n", 2, 0);
	}
	return (return_value);
}

int	parse_second(char *str, t_list **all_cmds, char ***envp)
{
	char	**separate;
	int		i;

	separate = ft_special_split(str, '|');
	i = 0;
	while (separate[i])
	{
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

	separate = ft_special_split(str, ';');
	i = 0;
	while (separate[i])
	{
		if (!parse_second(separate[i], all_cmds, envp))
			return(0);
		free(separate[i]);
		ft_lst_free(*all_cmds);
		i++;
	}
	free(separate);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	char				*str;
	char				**envp_cpy;
	t_list				*all_cmds;

	(void)ac;
	(void)av;
	envp_cpy = ft_envpdup(envp);
	ft_sig_manage(1);
	all_cmds = NULL;
	if (ac >= 3 && !ft_strncmp(av[1], "-c", 3))
  	{
    	int exit_status = parse_first(av[2], &all_cmds, &envp_cpy);
    	exit(exit_status);
  	}
	else
		while (1)
		{
			all_cmds = NULL;
			str = readline("==> ");
			add_history(str);
			if (!str)
			{
				write(STDOUT_FILENO, "exit\n", 5);
				return (1);
			}
			parse_first(str, &all_cmds, &envp_cpy);
			free(str);
		}
	return (0);
}
