/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:55:22 by user42            #+#    #+#             */
/*   Updated: 2021/11/16 20:54:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ft_close_pipe(int **pipefd, int nb, int j)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (i != j - 1)
			close(pipefd[i][0]);
		if (i != j)
			close(pipefd[i][1]);
		i++;
	}
}

static void	ft_set_pipe(int **pipefd, int i, int cmd_nbr)
{
	ft_close_pipe(pipefd, cmd_nbr - 1, i);
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
	else if (i == 0 && cmd_nbr > 1)
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
	while (++i < cmd_nbr - 1)
		pipe((*pipefd)[i]);
}

int ft_do_one(t_list *cmd, int **pipefd, char ***envp)
{
	pid_t pid;
	int	i;

	i = 0;
	if (cmd->funct == NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_sig_manage(0);
			ft_set_pipe(pipefd, 0, 1);
			execve(cmd->arg[0], cmd->arg, *envp);
		}
		waitpid(-1, &i, WUNTRACED);
	}
	else
		i = cmd->funct(cmd->arg, envp, cmd->fd1);
	return (i);
}

int	ft_pipe(t_list *cmd, char ***envp)
{
	pid_t	*pid;
	int		**pipefd;
	int		cmd_nbr;
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	cmd_nbr = ft_lst_len(cmd);
	ft_prep(&pipefd, &pid, cmd_nbr);
	if (cmd_nbr == 1)
		ft_do_one(cmd, pipefd, envp);
	while (++i < cmd_nbr && cmd_nbr > 1)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			ft_sig_manage(0);
			ft_set_pipe(pipefd, i, cmd_nbr);
			if (cmd->funct == NULL)
				execve(cmd->arg[0], cmd->arg, *envp);
			else
				i = cmd->funct(cmd->arg, envp, cmd->fd1);
			exit(i);
		}
		cmd = cmd->next;
	}
	i = -1;
	while (++i < cmd_nbr && cmd_nbr > 1)
		waitpid(-1, &ret, WUNTRACED);
	ft_last_cmd(ret, *envp);
	ft_free_pipe(pipefd, pid, cmd_nbr);
	return (0);
}
