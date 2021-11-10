/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:03:29 by user42            #+#    #+#             */
/*   Updated: 2021/11/10 15:09:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_update_env(char **envp, int *pipefd, int cmd_nbr)
{
	char	str[2];
	char	*stock;
	int		i;

	stock = NULL;
	str[1] = '\0';
	i = 0;
	close(pipefd[1]);
	while (read(pipefd[0], str, 1))
		stock = ft_strjoin(stock, ft_strdup(str));
	if (!stock)
		return ;
	while (ft_strncmp(envp[i], "PWD=", 4))
		i++;
	if (ft_strncmp(envp[i] + 4, stock, ft_strlen(envp[i]) + 1))
	{
		chdir(stock);
		free(envp[i]);
		envp[i] = ft_strjoin(ft_strdup("PWD="), ft_strdup(stock));
		if (cmd_nbr > 1)
			printf("(pwd now: %s)\n", ft_relpath());
	}
	free(stock);
}

void	ft_check_env(char **envp, int *pipefd)
{
	int i;
	char	*str;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PWD=", 4))
		i++;
	str = getcwd(NULL, 0);
	if (ft_strncmp(envp[i] + 4, str, ft_strlen(str) + 1))
	{
		write(pipefd[1], str, ft_strlen(str));
		write(pipefd[1], "\0", 1);
		free(str);
	}
}

char	**ft_envpdup(char **envp)
{
	int i;
	char	**cp;

	i = 0;
	while (envp[i])
		i++;
	cp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		cp[i] = ft_strdup(envp[i]);
		i++;
	}
	cp[i] = NULL;
	return (cp);
}
