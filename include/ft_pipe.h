/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:03:57 by user42            #+#    #+#             */
/*   Updated: 2021/11/19 19:53:00 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPE_H
# define FT_PIPE_H

typedef struct s_data
{
	int				**pipefd;
	pid_t			*pid;
	int				cmd_nbr;
	int				ret;
	char			***envp;
}				t_data;

int		ft_pipe(t_list *cmd, char ***envp);
int		ft_do_one(t_list *cmd, t_data *data, int i);
int		ft_do_child(t_data *data, t_list *cmd, int i);
t_data	*ft_prep(t_list *cmd, char ***envp);
void	ft_free_pipe(t_data *data);
void	ft_set_pipe(t_data *data, int i, t_list *cmd);
void	ft_close_pipe(t_data *data);

#endif
