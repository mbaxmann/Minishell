/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:36:30 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/31 14:13:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>

int		get_next_line(int fd, char **line);
int		ft_getbuffer(int fd, char **stock);
int		ft_getbuffer2(char **buffer, char **stock, int *rd_return, int fd);
int		ft_stock(char **stock, char **line);
int		ft_stock2(char **stock, char **line, int *i, int *j);

#endif
