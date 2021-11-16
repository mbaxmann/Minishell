/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:25:09 by user42            #+#    #+#             */
/*   Updated: 2021/11/15 18:02:45 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ft_handler(int signum)
{
	if (signum == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		if (rl_line_buffer[0] == '\0')
		{
			rl_replace_line("", 1);
			rl_on_new_line();
			rl_redisplay();
		}
	}
	else if (signum == SIGQUIT)
		return ;
}

void	ft_sig_manage(int mode)
{
	struct sigaction	sa;

	if (mode == 1)
		sa.sa_handler = ft_handler;
	else
		sa.sa_handler = SIG_DFL;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}
