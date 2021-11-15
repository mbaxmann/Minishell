/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:03:29 by user42            #+#    #+#             */
/*   Updated: 2021/11/15 16:51:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_getenv(char *env, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(env, envp[i], ft_strlen(env)))
			return (ft_strdup(envp[i] + ft_strlen(env) + 1));
		i++;
	}
	return (NULL);
}

void	ft_last_cmd(int wstatus, char **envp)
{
	int 	i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (WIFEXITED(wstatus))
	{
		printf("test le wstatus: %d\n", WEXITSTATUS(wstatus));
		tmp = ft_itoa(WEXITSTATUS(wstatus), 'd');
	}
	else if (WIFSIGNALED(wstatus))
	{
		printf("stopped: %d\n", WTERMSIG(wstatus));
	}
	while (ft_strncmp(envp[i], "?=", 2))
		i++;
	free(envp[i]);
	envp[i] = ft_strjoin(ft_strdup("?="), tmp);

}

void	ft_getenv_var(char **separate, char **envp)
{
	int		i;
	char	*tmp;

	i = 0;
	while (separate[i])
	{
		if (separate[i][0] == '$')
		{
			tmp = ft_getenv(separate[i] + 1, envp);
			free(separate[i]);
			separate[i] = tmp;
		}
		i++;
	}
}

char	**ft_envpdup(char **envp)
{
	int i;
	char	**cp;

	i = 0;
	while (envp[i])
		i++;
	cp = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (envp[i])
	{
		cp[i] = ft_strdup(envp[i]);
		i++;
	}
	cp[i] = ft_strdup("?=0");
	i++;
	cp[i] = NULL;
	return (cp);
}