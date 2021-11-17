/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:03:11 by user42            #+#    #+#             */
/*   Updated: 2021/11/17 19:54:55 by user42           ###   ########.fr       */
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

static char	*ft_path_env(char **envp, int i)
{
	char	*str;
	char	*path_env;
	int		j;

	str = NULL;
	j = 0;
	while (envp[j] && ft_strncmp(envp[j], "PATH=", 5))
		j++;
	if (envp[j] == NULL)
		return (NULL);
	path_env = envp[j];
	path_env += 5;
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
		path_env += j + 1;
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
		path = ft_path_env(envp, i);
		if (path)
			path = ft_strjoin(path, ft_strdup(cmd->arg[0]));
		i++;
	}
	return (-1);
}
