/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:55:22 by user42            #+#    #+#             */
/*   Updated: 2021/11/18 21:51:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ft_close_pipe(int **pipefd, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		close(pipefd[i][0]);
		close(pipefd[i][1]);
		i++;
	}
}

void	heredoc(char* delimiter)
{
	char	*str;
	char	*aux;
	int		tmp_fd;
	
	str = (char*) malloc (sizeof(char*));
	str = NULL;
	aux = NULL;
	while (!aux || ft_strncmp(delimiter, aux, ft_strlen(delimiter)))
	{
		str = ft_strjoin(str, aux);
		str = ft_strjoin(str, ft_strdup("\n"));
		aux = readline(">");
	}
	free(aux);
	aux = ttyname(STDIN_FILENO);
	tmp_fd = open(aux, O_WRONLY);
	write(tmp_fd, str, ft_strlen(str));
	close(tmp_fd);
	free(str);
}

static void	ft_set_pipe(int **pipefd, int i, int cmd_nbr, t_list *cmd)
{
	if (cmd->fd1 != -1 && dup2(cmd->fd1, STDOUT_FILENO) < 0)
		ft_error(errno);
	if (cmd->fd2 >= 0 && dup2(cmd->fd2, STDIN_FILENO) < 0)
		ft_error(errno);
	if (cmd->fd2 == -42)
		heredoc(cmd->aux);
	else if (i != 0)
	{
		dup2(pipefd[i - 1][0], STDIN_FILENO);
		if (i != cmd_nbr - 1)
		{
			if (dup2(pipefd[i][1], STDOUT_FILENO) < 0)
				ft_error(errno);
		}
	}
	else if (i == 0 && cmd_nbr > 1)
	{
		if (dup2(pipefd[i][1], STDOUT_FILENO) < 0)
			ft_error(errno);
	}
	ft_close_pipe(pipefd, cmd_nbr - 1);
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
			ft_set_pipe(pipefd, 0, 1, cmd);
			i = ft_exec(cmd, *envp);
			if (i == -1)
				printf("minishell: %s: No such file or directori\n",  cmd->arg[0]);
			exit(1);
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
		ret = ft_do_one(cmd, pipefd, envp);
	while (++i < cmd_nbr && cmd_nbr > 1)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			ft_sig_manage(0);
			ft_set_pipe(pipefd, i, cmd_nbr, cmd);
			if (cmd->funct == NULL)
				i = ft_exec(cmd, *envp);
			else
				i = cmd->funct(cmd->arg, envp, cmd->fd1);
			exit(i);
		}
		cmd = cmd->next;
	}
	i = -1;
	ft_close_pipe(pipefd, cmd_nbr - 1);
	while (++i < cmd_nbr && cmd_nbr > 1)
	{
		waitpid(-1, &ret, WUNTRACED);
	}
	ft_last_cmd(ret, *envp);
	ft_free_pipe(pipefd, pid, cmd_nbr);
	return (0);
}
