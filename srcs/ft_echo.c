/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:46:42 by user42            #+#    #+#             */
/*   Updated: 2021/10/25 18:17:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	*ft_echo(void *param)
{
	char	*str;

	str = ((t_list *)param)->argument;
	ft_putstr_fd(str, 1, 0);
	if (((t_list *)param)->option != 'n')
		write(1, "\n", 1);
	return (NULL);
}
