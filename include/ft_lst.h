#ifndef FT_LST_H
# define FT_LST_H

typedef struct	s_list
{
	char			*name;
	char			**arg;
	struct s_list	*next;
}				t_list;

t_list	*ft_lst_create(char *name, char **arg);
t_list	*ft_lst_add(t_list *first, t_list *to_add);
void	ft_lst_free(t_list *first);
int		ft_lst_len(t_list *first);

# endif
