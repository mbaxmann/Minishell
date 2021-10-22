#ifndef FT_PIPE_H
# define FT_PIPE_H

void	*ft_do_parent(t_list *cmd, int pipefd[2]);
void	ft_do_child(t_list *cmd, int pipefd[2]);
void	*ft_pipe(t_list *cmd);

# endif
