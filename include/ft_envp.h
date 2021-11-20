/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:08:08 by user42            #+#    #+#             */
/*   Updated: 2021/11/20 18:48:56 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENVP_H
# define FT_ENVP_H

char	**ft_envpdup(char **envp);
void	ft_getenv_var(char **separate, char **envp, int s_quote, int d_quote);
void	ft_last_cmd(int wstatus, char **envp, char *str);
void	ft_forget_env(char	**env_cpy);

#endif
