#ifndef FT_LST_H
# define FT_LST_H

typedef struct	s_list
{
	void			*(*funct)(void *param);
	struct s_list	*next;
}				t_list;

t_list	*ft_lst_create(void *(*funct)(void *param));
t_list	*ft_lst_add(t_list *first, t_list *to_add);
void	ft_lst_free(t_list *first);

# endif
