#include <stdlib.h>
#include "ft_list.h"

t_list  *ft_create_elem(void *data)
{
    t_list  *l;
    if (!(l = malloc(sizeof(t_list))))
        return (NULL);
    l->next = NULL;
    l->data = data;
    return (1);
}