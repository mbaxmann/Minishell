/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:32:25 by user42            #+#    #+#             */
/*   Updated: 2021/11/19 19:53:52 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_do_child(t_data *data, t_list *cmd, int i)
{
	if (data->pid[i] == 0)
	{
		ft_sig_manage(0);
		ft_set_pipe(data, i, cmd);
		if (cmd->funct == NULL)
			i = ft_exec(cmd, *(data->envp));
		else
			i = cmd->funct(cmd->arg, data->envp, cmd->fd1);
		exit(i);
	}
	return (0);
}

void	ft_free_pipe(t_data *data)
{
	int	i;

	i = -1;
	free(data->pid);
	while (++i < data->cmd_nbr - 1)
		free(data->pipefd[i]);
	free(data->pipefd);
	free(data);
}

t_data	*ft_prep(t_list *cmd, char ***envp)
{
	int		i;
	t_data	*data;

	i = -1;
	data = (t_data *)malloc(sizeof(t_data));
	data->cmd_nbr = ft_lst_len(cmd);
	data->pipefd = (int **)malloc(sizeof(int *) * (data->cmd_nbr - 1));
	while (++i < data->cmd_nbr - 1)
		data->pipefd[i] = (int *)malloc(sizeof(int) * 2);
	data->pid = (pid_t *)malloc(sizeof(pid_t) * data->cmd_nbr);
	i = -1;
	while (++i < data->cmd_nbr - 1)
		pipe((data->pipefd)[i]);
	data->ret = 0;
	data->envp = envp;
	return (data);
}

int	ft_do_one(t_list *cmd, t_data *data, int i)
{
	pid_t	pid;

	data->cmd_nbr = 1;
	if (cmd->funct == NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_sig_manage(0);
			ft_set_pipe(data, 0, cmd);
			i = ft_exec(cmd, *(data->envp));
			if (i == -1)
			{
				ft_putstr_fd("minishell: ", 2, 0);
				ft_putstr_fd(cmd->arg[0], 2, 0);
				ft_putendl_fd(": command not found", 2);
			}
			exit(1);
		}
		waitpid(-1, &i, WUNTRACED);
	}
	else
		i = cmd->funct(cmd->arg, data->envp, cmd->fd1);
	return (i);
}
