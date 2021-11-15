/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:08:08 by user42            #+#    #+#             */
/*   Updated: 2021/11/15 16:26:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENVP_H
# define FT_ENVP_H

char	**ft_envpdup(char **envp);
char	*ft_getenv(char *env, char **envp);
void	ft_getenv_var(char **separate, char **envp);
void	ft_last_cmd(int wstatus, char **envp);

# endif
