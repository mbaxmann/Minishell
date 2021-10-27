#include "../include/minishell.h"

t_list	*ft_lst_create(char *name, char **arg)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	new->name = name;
	new->arg = arg;
	new->next = NULL;
	return (new);
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
		free(tmp->arg);
		free(tmp->name);
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
