/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:14:34 by user42            #+#    #+#             */
/*   Updated: 2021/11/19 10:03:49 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

int		ft_echo(char **av, char ***envp, int fd1);
int		ft_cd(char **av, char ***envp, int fd1);
int		ft_pwd(char **av, char ***envp, int fd1);
int		ft_env(char **av, char ***envp, int fd1);
int		ft_export(char **av, char ***envp, int fd1);
int		ft_unset(char **av, char ***envp, int fd1);
int		ft_exit(char **av, char ***envp, int fd1);
void	ft_export2(char **envp, int fd1);

#endif
