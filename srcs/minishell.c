#include "../include/minishell.h"

int	main(int ac, char **av)
{
	char	*str;

	while (1)
	{
		str = readline("==> ");
		printf("%s has been read\n", str);
		add_history(str);
		//ret1 = ft_parsing(str);
		//ret2 = ft_pipe(ret1);
		//ft_redirection(ret2);
		free(str);
	}
	return (0);
}
