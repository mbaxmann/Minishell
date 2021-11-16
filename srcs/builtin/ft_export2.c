/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:35:47 by user42            #+#    #+#             */
/*   Updated: 2021/11/16 20:17:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_smaller(int i, int j, char **envp)
{
	int	k;

	k = 0;
	if (envp[j] == NULL)
		return (1);
	while (envp[i][k] == envp[j][k])
	{
		k++;
		if (envp[i][k] == '=')
			return (1);
	}
	if (envp[i][k] <= envp[j][k])
		return (1);
	return (0);
}

static int	ft_get_sort(char **envp, int len)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < len)
	{
		while (envp[i] == NULL && i < len)
			i++;
		while (ft_smaller(i, j, envp) && j < len && i < len)
			j++;
		if (j == len)
			return (i);
		else if (i == len)
			return (i);
		i++;

	}
	return (i);
}

static void	ft_write(int i, int fd1, char **envp_cp)
{
	int 	j;
	char	c;

	j = 0;
	c = 34;
	ft_putstr_fd("declare -x ", fd1, 0);
	while (envp_cp[i][j] && envp_cp[i][j] != '=')
		write(fd1, &envp_cp[i][j++], 1);
	if (envp_cp[i][j] == '=')
	{
		write(fd1, "=", 1);
		write(fd1, &c, 1);
		ft_putstr_fd(envp_cp[i] + j + 1, fd1, 0);
		write(fd1, &c, 1);
	}
	write(fd1, "\n", 1);
}

void	ft_export2(char **envp, int fd1)
{
	char	**envp_cp;
	int		i;
	int		len;

	envp_cp = ft_envpdup(envp);
	len = 0;
	while (envp_cp[len])
		len++;
	free(envp_cp[len]);
	len--;
	i = ft_get_sort(envp_cp, len);
	while (i != len)
	{
		if (ft_strncmp(envp_cp[i], "?=", 2))
			ft_write(i, fd1, envp_cp);
		free(envp_cp[i]);
		envp_cp[i] = NULL;
		i = ft_get_sort(envp_cp, len);
	}
	free(envp_cp);
}
