/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:56:48 by user42            #+#    #+#             */
/*   Updated: 2021/11/17 19:51:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_not_exist(char **envp, char *str)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], str, ft_strlen(str)))
			if (envp[i][ft_strlen(str)] == '='
				|| envp[i][ft_strlen(str)] == '\0')
				return (0);
		i++;
	}
	return (1);
}

static void	ft_delete(char ***envp, char *str)
{
	int		i;
	int		k;
	int		len;
	char	**envp_cp;
	char	**tmp;

	i = 0;
	k = 0;
	tmp = *envp;
	if (ft_not_exist(*envp, str))
		return ;
	while (tmp[i])
		i++;
	len = i;
	envp_cp = (char **)malloc(sizeof(char *) * i);
	i = 0;
	while (i + k < len)
	{
		if (!ft_strncmp(tmp[i + k], str, ft_strlen(str)))
		{
			free(tmp[i + k]);
			k++;
			i--;
		}
		else
			envp_cp[i] = tmp[i + k];
		i++;
	}
	envp_cp[len - 1] = NULL;
	free(*envp);
	*envp = envp_cp;
}

int	ft_unset(char **av, char ***envp, int fd1)
{
	int	i;

	i = 1;
	if (fd1 == -1)
		fd1 = STDOUT_FILENO;
	while (av[i])
	{
		if (!ft_valid(av[i]))
		{
			ft_putstr_fd("minishell: unset: « ", fd1, 0);
			ft_putstr_fd(av[i], fd1, 0);
			ft_putstr_fd("» : invalid identifier\n", fd1, 0);
			return (1);
		}
		ft_delete(envp, av[i]);
		i++;
	}
	return (0);
}
