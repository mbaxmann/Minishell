/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:03:29 by user42            #+#    #+#             */
/*   Updated: 2021/11/09 16:45:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_update_env(char **envp, int *pipefd)
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
	while (ft_strncmp(envp[i], "PWD=", 4))
		i++;
	if (ft_strncmp(envp[i] + 4, stock, ft_strlen(envp[i]) + 1))
	{
		chdir(stock);
		free(envp[i]);
		envp[i] = ft_strjoin(ft_strdup("PWD="), ft_strdup(stock));
		printf("(pwd now: %s)\n", ft_relpath());
	}
	free(stock);
}

void	ft_check_env(char **envp)
{
	int i;
	char	*str;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PWD=", 4))
		i++;
	str = getcwd(NULL, 0);
	if (ft_strncmp(envp[i] + 4, str, ft_strlen(str) + 1))
	{
		write(STDOUT_FILENO, str, ft_strlen(str));
		write(STDOUT_FILENO, "\0", 1);
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
	cp = (char **)malloc(sizeof(char *) * i);
	i = 0;
	while (envp[i])
	{
		cp[i] = ft_strdup(envp[i]);
		i++;
	}
	cp[i] = NULL;
	return (cp);
}
