/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:03:11 by user42            #+#    #+#             */
/*   Updated: 2021/11/19 18:57:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*ft_nstrdup(char *str, int i)
{
	char	*ret;
	int		j;

	j = 0;
	ret = NULL;
	if (!str)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		ret[j] = str[j];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

static char	*ft_path_env(char **envp, int i, int j)
{
	char	*str;
	char	*path_env;

	str = NULL;
	while (envp[j] && ft_strncmp(envp[j], "PATH=", 5))
		j++;
	if (!envp[j])
		return (NULL);
	path_env = envp[j] + 5;
	j = 0;
	while (i && path_env)
	{
		if (str)
			free(str);
		if (i > 1 && !path_env[j])
			return (NULL);
		while (path_env[j] && path_env[j] != ':')
			j++;
		str = ft_nstrdup(path_env, j);
		path_env += j + (path_env[j] == ':');
		j = 0;
		i--;
	}
	str = ft_strjoin(str, ft_strdup("/"));
	return (str);
}

int	ft_exec(t_list *cmd, char **envp)
{
	int		ret;
	int		i;
	char	*path;

	ret = 0;
	i = 1;
	path = ft_strdup(cmd->arg[0]);
	while (path)
	{
		ret = execve(path, cmd->arg, envp);
		if (path)
			free(path);
		path = ft_path_env(envp, i, 0);
		if (path)
			path = ft_strjoin(path, ft_strdup(cmd->arg[0]));
		i++;
	}
	return (-1);
}

t_list	*ft_builtins(char **separate, t_list **all_cmds)
{
	t_list	*index;

	if (!ft_strncmp("echo", separate[0], 5))
		index = ft_lst_push(all_cmds, &ft_echo, separate);
	else if (!ft_strncmp("cd", separate[0], 3))
		index = ft_lst_push(all_cmds, &ft_cd, separate);
	else if (!ft_strncmp("pwd", separate[0], 4))
		index = ft_lst_push(all_cmds, &ft_pwd, separate);
	else if (!ft_strncmp("exit", separate[0], 6))
		index = ft_lst_push(all_cmds, &ft_exit, separate);
	else if (!ft_strncmp("env", separate[0], 4))
		index = ft_lst_push(all_cmds, &ft_env, separate);
	else if (!ft_strncmp("export", separate[0], 7))
		index = ft_lst_push(all_cmds, &ft_export, separate);
	else if (!ft_strncmp("unset", separate[0], 6))
		index = ft_lst_push(all_cmds, &ft_unset, separate);
	else if (!ft_strncmp("./", separate[0], 2))
		index = ft_lst_push(all_cmds, NULL, separate);
	else if (!ft_strncmp("/", separate[0], 1))
		index = ft_lst_push(all_cmds, NULL, separate);
	else
		index = NULL;
	return (index);
}

void	ft_last_cmd(int wstatus, char **envp)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (WIFSIGNALED(wstatus))
	{
		if (WCOREDUMP(wstatus))
			printf("Quit (core dumped)\n");
		tmp = ft_itoa(WTERMSIG(wstatus), 'd');
	}
	else if (WIFEXITED(wstatus))
		tmp = ft_itoa(WEXITSTATUS(wstatus), 'd');
	while (ft_strncmp(envp[i], "?=", 2))
		i++;
	free(envp[i]);
	envp[i] = ft_strjoin(ft_strdup("?="), tmp);
}
