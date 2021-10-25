/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:55:22 by user42            #+#    #+#             */
/*   Updated: 2021/10/25 17:37:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Ft_pipe prend en parametre une liste chainée.
Chaque élément de la liste contient un pointeur sur fonction. (ici les fonction correspondent à des commande du minishell)
Ft_pipe retourn un pointeur vers le résultat obtenu.*/

#include "../include/minishell.h"

void	*ft_do_parent(t_list *cmd, int pipefd[2])
{
	char	*stock;
	char	*buffer;

	stock = NULL;
	buffer = NULL;
	if (cmd->next)
	{
		wait (NULL);
		while (get_next_line(pipefd[0], &buffer))
		{
			stock = ft_strjoin(stock, buffer);
			free(buffer);
		}
		stock = ft_strjoin(stock, buffer);
		free(buffer);
		cmd->argument = stock;
		cmd->funct(cmd);
		return (stock);
	}
	else
	{
		cmd->funct(cmd);
		return (NULL);
	}
}

void	ft_do_child(t_list *cmd, int pipefd[2])
{
	char	*stock;

	stock = (char *)ft_pipe(cmd->next);
	if (stock)
	{
		write(pipefd[1], stock, ft_strlen(stock));
		free(stock);
	}
}

void	*ft_pipe(t_list *cmd)
{
	pid_t	pid;
	int		pipefd[2];

	if (cmd == NULL)
			return (NULL);
	pid = fork();
	pipe(pipefd);
	if (pid > 0)
		return (ft_do_parent(cmd, pipefd);
	else
		ft_do_child(cmd, pipefd);
	return (0);
}
