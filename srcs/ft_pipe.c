/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:55:22 by user42            #+#    #+#             */
/*   Updated: 2021/11/20 18:49:24 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_close_pipe(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->cmd_nbr - 1)
	{
		close(data->pipefd[i][0]);
		close(data->pipefd[i][1]);
		i++;
	}
}

void	ft_set_pipe(t_data *data, int i, t_list *cmd)
{
	if (cmd->fd1 != -1 && dup2(cmd->fd1, STDOUT_FILENO) < 0)
		ft_error(errno);
	if (cmd->fd2 >= 0 && dup2(cmd->fd2, STDIN_FILENO) < 0)
		ft_error(errno);
	else if (i != 0)
	{
		dup2(data->pipefd[i - 1][0], STDIN_FILENO);
		if (i != data->cmd_nbr - 1)
		{
			if (dup2(data->pipefd[i][1], STDOUT_FILENO) < 0)
				ft_error(errno);
		}
	}
	else if (i == 0 && data->cmd_nbr > 1)
	{
		if (dup2(data->pipefd[i][1], STDOUT_FILENO) < 0)
			ft_error(errno);
	}
	ft_close_pipe(data);
}

int	ft_pipe(t_list *cmd, char ***envp)
{
	t_data	*data;
	int		i;

	i = -1;
	data = ft_prep(cmd, envp);
	if (data->cmd_nbr == 1)
		data->ret = ft_do_one(cmd, data, 0);
	while (++i < data->cmd_nbr && data->cmd_nbr > 1)
	{
		data->pid[i] = fork();
		ft_do_child(data, cmd, i);
		cmd = cmd->next;
	}
	i = -1;
	ft_close_pipe(data);
	while (++i < data->cmd_nbr && data->cmd_nbr > 1)
		waitpid(-1, &data->ret, WUNTRACED);
	ft_last_cmd(data->ret, *envp, NULL);
	ft_free_pipe(data);
	return (0);
}
