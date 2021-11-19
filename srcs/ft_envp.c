/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:03:29 by user42            #+#    #+#             */
/*   Updated: 2021/11/19 11:37:06 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_getenv(char *env, int end, char **envp)
{
	int	i;

	i = 0;
	if (end <= 0)
		return (NULL);
	while (envp[i])
	{
		if (!ft_strncmp(env, envp[i], end))
			return (ft_strdup(envp[i] + end + 1));
		i++;
	}
	return (NULL);
}

char	*put_env(char *str, int j, char **envp, int *moved)
{
	int		end;
	char	*aux1;
	char	*aux2;

	end = j + 1;
	while (str[end] && str[end] != ' ' && str[end] != '\"' && str[end] != '\''
		&& str[end] != '\\' && str[end] != ';' && str[end] != '.'
		&& str[end] != '=' && str[end] != '.' && str[end] != '$'
		&& str[end] != '/')
		end++;
	if (str[j + 1] >= '0' && str[j + 1] <= '9')
		end = j + 2;
	if (str[end])
		aux1 = ft_strdup(str + end);
	else
		aux1 = NULL;
	aux2 = ft_getenv(str + 1 + j, end - j - 1, envp);
	str[j] = '\0';
	*moved = ft_strlen(aux2);
	aux2 = ft_strjoin(str, aux2);
	if (aux1)
		aux2 = ft_strjoin(aux2, aux1);
	return (aux2);
}

void	ft_getenv_var(char **separate, char **envp, int s_quote, int d_quote)
{
	int		i;
	int		j;
	int		aux;

	i = -1;
	while (separate[++i])
	{
		j = -1;
		s_quote = 0;
		d_quote = 0;
		while (separate[i][++j])
		{
			if (!d_quote)
				s_quote = (s_quote + (separate[i][j] == '\'')) % 2;
			if (!s_quote)
				d_quote = (d_quote + (separate[i][j] == '\"')) % 2;
			if (separate[i][j] == '$' && !s_quote && separate[i][j + 1] != ' ')
			{
				separate[i] = put_env(separate[i], j, envp, &aux);
				if (!separate[i][0])
					separate[i][0] = 127;
				j += aux - 2;
			}
		}
	}
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

char	**ft_envpdup(char **envp)
{
	int		i;
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
