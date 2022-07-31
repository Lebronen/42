#include <stdlib.h>
#include "ft_list.h"

void    ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
    if (!begin_list)
        return;
    ft_list_clear(begin_list->next, free_fct);
    if (free_fct)
        free_fct(begin_list->data);
    free(begin_list);
}