#include "../include/minishell"

t_list	*ft_lst_create(void	*(*funct)(void *param))
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	new->funct = funct;
	new->next = NULL;
}

t_list	*ft_lst_add(t_list *first, t_list *to_add)
{
	t_list	*tmp;

	if (!first)
		return (to_add);
	tmp = first;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = to_add;
	return (first);
}

void	ft_lst_free(t_list *first)
{
	t_list *tmp;

	while (first)
	{
		tmp = first;
		first = first->next;
		free(tmp->funct);
		free(tmp);
	}
}
