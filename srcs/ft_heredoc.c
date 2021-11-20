/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 23:09:35 by user42            #+#    #+#             */
/*   Updated: 2021/11/20 01:29:30 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_add_heredoc(t_list **index)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*new;

	tmp1 = *index;
	tmp2 = NULL;
	while (tmp1)
	{
		if (tmp1->fd2 == -42)
		{
			new = ft_lst_create(NULL, NULL);
			new->next = tmp1;
			if (tmp2)
				tmp2->next = new;
			else
				*index = new;
		}
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	tmp1 = *index;
}

char	**heredoc(char *delimiter, char **envp)
{
	char	*str;
	char	*aux;
	char	**separate;

	str = ft_strdup("echo ");
	aux = NULL;
	while (!aux || ft_strncmp(delimiter, aux, ft_strlen(delimiter)))
	{
		str = ft_strjoin(str, aux);
		str = ft_strjoin(str, ft_strdup("\n\1"));
		aux = readline(">");
	}
	free(aux);
	separate = ft_split(str, '\1');
	free(str);
	ft_getenv_var(separate, envp, 0, 0);
	free(delimiter);
	return (separate);
}
