/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:03:29 by user42            #+#    #+#             */
/*   Updated: 2021/11/11 12:31:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
	
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
