/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 23:09:35 by user42            #+#    #+#             */
/*   Updated: 2021/11/20 00:13:54 by user42           ###   ########.fr       */
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

void	heredoc(char *delimiter, int *pipefd)
{
	char	*str;
	char	*aux;
	//int		tmp_fd;

	str = (char *)malloc(sizeof(char));
	str = NULL;
	aux = NULL;
	while (!aux || ft_strncmp(delimiter, aux, ft_strlen(delimiter)))
	{
		str = ft_strjoin(str, aux);
		str = ft_strjoin(str, ft_strdup("\n"));
		aux = readline(">");
	}
	free(aux);
	//aux = ttyname(STDIN_FILENO);
	//tmp_fd = open(aux, O_WRONLY);
	write(pipefd[1], str, ft_strlen(str));
	close(pipefd[1]);
	free(str);
}
