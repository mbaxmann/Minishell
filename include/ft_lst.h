#ifndef FT_LST_H
# define FT_LST_H

typedef struct	s_list
{
	void			(*funct)(char **param);
	char			**arg;
	int				fd1;
	int				fd2;
	struct s_list	*next;
}				t_list;

t_list	*ft_lst_create(void (*funct)(char **param), char **arg);
void	ft_lst_free(t_list *first);
int		ft_lst_len(t_list *first);
void	ft_lst_push(t_list **first, void (*funct)(char **param), char **separate);

# endif
