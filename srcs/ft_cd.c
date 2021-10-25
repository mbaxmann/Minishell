/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:47:08 by user42            #+#    #+#             */
/*   Updated: 2021/10/25 18:12:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	*ft_cd(void *param)
{
	t_list	*lst;

	lst = (t_list *)param;
	if (chdir(lst->argument) == -1)
		printf("cd: no such file or directory: %s\n", lst->argument);
	return (getcwd(NULL, 0));
}
