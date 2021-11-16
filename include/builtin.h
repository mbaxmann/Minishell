/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:14:34 by user42            #+#    #+#             */
/*   Updated: 2021/11/16 22:15:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

int		ft_echo(char **av, char ***envp, int fd1);
int		ft_cd(char **av, char ***envp, int fd1);
int		ft_pwd(char **av, char ***envp, int fd1);
int		ft_env(char **av, char ***envp, int fd1);
int		ft_export(char **av, char ***envp, int fd1);
int		ft_unset(char **ev, char ***envp, int fd1);
void	ft_export2(char **envp, int fd1);

# endif