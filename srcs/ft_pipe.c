/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarlo <oscarlo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:55:22 by user42            #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ft_close_pipe(int **pipefd, int nb, int j)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (i != j)
			close(pipefd[i][0]);
		if (i != j + 1)
			close(pipefd[i][1]);
		i++;
	}
}

static void	ft_set_pipe(int **pipefd, int i, int cmd_nbr)
{
	ft_close_pipe(pipefd, cmd_nbr - 1, i - 1);
	if (i != 0)
	{
		dup2(pipefd[i - 1][0], STDIN_FILENO);
		close(pipefd[i - 1][0]);
		if (i != cmd_nbr - 1)
		{
			dup2(pipefd[i][1], STDOUT_FILENO);
			close(pipefd[i][1]);
		}
	}
	else
	{
		dup2(pipefd[i][1], STDOUT_FILENO);
		close(pipefd[i][1]);
	}
}

static void	ft_free_pipe(int **pipefd, pid_t *pid, int nb)
{
	int	i;

	i = -1;
	free(pid);
	while (++i < nb - 1)
		free(pipefd[i]);
	free(pipefd);
}

static void	ft_prep(int ***pipefd, pid_t **pid, int cmd_nbr)
{
	int	i;

	i = -1;
	*pipefd = (int **)malloc(sizeof(int *) * (cmd_nbr - 1));
	while (++i < cmd_nbr - 1)
		(*pipefd)[i] = (int *)malloc(sizeof(int) * 2);
	*pid = (pid_t *)malloc(sizeof(pid_t) * cmd_nbr);
	i = -1;
	while (++i < cmd_nbr)
		pipe((*pipefd)[i]);
}

int	ft_pipe(t_list *cmd)
{
	pid_t	*pid;
	int		**pipefd;
	int		cmd_nbr;
	int		i;

	i = -1;
	cmd_nbr = ft_lst_len(cmd);
	ft_prep(&pipefd, &pid, cmd_nbr);
	while (++i < cmd_nbr)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			if (cmd_nbr > 1)
				ft_set_pipe(pipefd, i, cmd_nbr);
			cmd->funct(cmd->arg);
			exit(0);
		}
		cmd = cmd->next;
	}
	i = -1;
	while (++i < cmd_nbr)
		waitpid(-1, NULL, 0);
	ft_free_pipe(pipefd, pid, cmd_nbr);
	return (0);
}
