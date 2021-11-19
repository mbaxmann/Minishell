/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:08:08 by user42            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/19 12:25:26 by user42           ###   ########.fr       */
=======
/*   Updated: 2021/11/19 10:05:40 by olozano-         ###   ########.fr       */
>>>>>>> 9b46dd9ae451d8fe76ef6174fc53ffdee64fce9a
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENVP_H
# define FT_ENVP_H

char	**ft_envpdup(char **envp);
void	ft_getenv_var(char **separate, char **envp, int s_quote, int d_quote);
void	ft_last_cmd(int wstatus, char **envp);

#endif
