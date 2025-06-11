#include "minishell.h"
#include "executor.h"
#include "test_ms.h"

void	print_path(char **path)
{
	if (!*path)
		return ;
	printf("%s\n", path[0]);
	print_path(path + 1);
}

void	testprint_args(char **args)
{
	while(*args)
	{
		printf("%s\n", *args);
		args++;
	}
}

void	testprint_lst(t_list *lst)
{
	if (!lst)
	{
		write(1, "", 1);
		return ;
	}
	printf("%s\n", (char *)lst->content);
	testprint_lst(lst->next);
}

void	testprint_rdct(t_rdct *node)
{
	if (!node)
	{
		write(1, "", 1);
		return ;
	}
	printf("path: %s\n", node->path);
	testprint_rdct(node->next);
}
