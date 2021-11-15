/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:21:19 by oscarlo           #+#    #+#             */
/*   Updated: 2021/11/11 12:51:21 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	shift_fd(char *file)
{
	(void) file;
	return ;
}

int	make_cmd(char *cmd, t_list **all_cmds)
{
	char	**separate;
	int		return_value;
	t_list	*index;

	return_value = 0;
	separate = ft_split(cmd, ' ');
	if (!strncmp("echo", separate[0], 5))
		index = ft_lst_push(all_cmds, &ft_echo, separate);
	else if (!strncmp("cd", separate[0], 3))
		index = ft_lst_push(all_cmds, &ft_cd, separate);
	else if (!strncmp("pwd", separate[0], 4))
		index = ft_lst_push(all_cmds, &ft_pwd, separate);
	else if (!strncmp("exit", separate[0], 6))
		exit(ft_atoi(separate[1]));
	else
	{
		index = ft_lst_push(all_cmds, NULL, separate);
		return_value = 1;
	}
	if (check_redirections(index) == -42)
	{
		ft_putendl_fd("ERROR in redirections", 2);
		return (1);
	}
	if (return_value)
	{
		ft_putstr_fd("minishell: ", (*all_cmds)->fd2, 0);
		ft_putstr_fd((*all_cmds)->arg[0], (*all_cmds)->fd2, 0);
		ft_putstr_fd(": command not found\n", (*all_cmds)->fd2, 0);
	}
	return (return_value);
}

int	parse_second(char *str, t_list **all_cmds, char **envp)
{
	char	**separate;
	int		i;

	separate = ft_split(str, '|');
	i = 0;
	while (separate[i])
	{
		if (make_cmd(separate[i], all_cmds))
			return (1);
		free(separate[i]);
		i++;
	}
	free(separate);
	ft_pipe(*all_cmds, envp);
	return (42);
}

int	parse_first(char *str, t_list **all_cmds, char **envp)
{
	char	**separate;
	int		i;

	separate = ft_split(str, ';');
	i = 0;
	while (separate[i])
	{
		parse_second(separate[i], all_cmds, envp);
		free(separate[i]);
		ft_lst_free(*all_cmds);
		i++;
	}
	free(separate);
	return (42);
}

int	main(int ac, char **av, char **envp)
{
	char	*str;
	char	**envp_cpy;
	t_list	*all_cmds;

	(void)ac;
	(void)av;
	envp_cpy = ft_envpdup(envp);
	while (1)
	{
		all_cmds = NULL;
		str = readline("==> ");
		add_history(str);
		if (!str)
			return (1);
		if (!parse_first(str, &all_cmds, envp_cpy))
		{
			free(str);
			return (1);
		}
		free(str);
	}
	return (0);
}
