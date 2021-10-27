#ifndef FT_PIPE_H
# define FT_PIPE_H

int		ft_pipe(t_list *cmd);
void	ft_close_pipe(int **pipefd, int nb, int j);
void	ft_set_pipe(int **pipefd, int i, int cmd_nbr);
void	ft_free_pipe(int **pipefd, pid_t *pid, int nb);

# endif
