#include "../include/minishell.h"

t_list	*ft_lst_create(int (*funct)(char **av, char ***envp, int fd1), char **arg)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	new->funct = funct;
	new->arg = arg;
	new->fd1 = -1;
	new->fd2 = -1;
	new->next = NULL;
	return (new);
}

t_list	*ft_lst_push(t_list **first, int (*funct)(char **av, char ***envp, int fd1),
		char **separate)
{
	t_list	*new;
	
	new = ft_lst_create(funct, separate);
	if (*first == NULL)
		*first = new;
	else
	{
		while ((*first)->next)
			*first = (*first)->next;
		(*first)->next = new;
	}
	return (new);
}

void	ft_lst_free(t_list *first)
{
	t_list *tmp;

	while (first)
	{
		tmp = first;
		first = first->next;
		free(tmp->arg);
		free(tmp);
	}
}

int		ft_lst_len(t_list *first)
{
	int	i;

	i = 0;
	while (first)
	{
		first = first->next;
		i++;
	}
	return (i);
}
