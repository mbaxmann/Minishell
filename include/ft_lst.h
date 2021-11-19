/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:27:46 by user42            #+#    #+#             */
/*   Updated: 2021/11/19 12:27:56 by user42           ###   ########.fr       */
=======
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:03:57 by olozano-          #+#    #+#             */
/*   Updated: 2021/11/19 10:05:19 by olozano-         ###   ########.fr       */
>>>>>>> 9b46dd9ae451d8fe76ef6174fc53ffdee64fce9a
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

typedef struct s_list
{
	int				(*funct)(char **av, char ***envp, int fd1);
	char			**arg;
	int				fd1;
	int				fd2;
	char			*aux;
	struct s_list	*next;
}				t_list;

<<<<<<< HEAD
t_list	*ft_lst_create(int (*funct)
			(char **av, char ***envp, int fd1), char **arg);
void	ft_lst_free(t_list *first);
int		ft_lst_len(t_list *first);
t_list	*ft_lst_push(t_list **first, int (*funct)
			(char **av, char ***envp, int fd1), char **separate);
=======
t_list	*ft_lst_create(int (*funct)(char **av, char ***envp, int fd1),
			char **arg);
void	ft_lst_free(t_list *first);
int		ft_lst_len(t_list *first);
t_list	*ft_lst_push(t_list **first,
			int (*funct)(char **av, char ***envp, int fd1), char **separate);
>>>>>>> 9b46dd9ae451d8fe76ef6174fc53ffdee64fce9a

#endif
