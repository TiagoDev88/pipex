#include <stdio.h>
#include "libft.h"
int main(void)
{
	char **resp;
	char *splt = "Hello My friend";
	char **respSPLIT;
	int i;
	i = 0;
	respSPLIT = ft_split(splt, ' ');
	
	t_list *list;
	t_list *node;

	list = NULL;
	while (respSPLIT[i])
	{
		node = ft_lstnew(respSPLIT[i]);
		ft_lstadd_back(&list, node);
		i++;
	}
	t_list *ptr;
	ptr = list;
	while (ptr)
	{
		printf("%s ", ptr->content);
		ptr = ptr->next;
	}
	ptr = list;
	while (ptr)
	{
		t_list *temp = ptr->next;
		free(ptr->content);
		free(ptr);
		ptr = temp;
	}
	free(respSPLIT);
	return (0);
}