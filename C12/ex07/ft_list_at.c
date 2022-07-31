#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

t_list  *ft_list_at(t_list *begin_list, unsigned int nbr)
{
    if (!begin_list)
        return (NULL);
    else if (nbr == 0)
        return (begin_list);
    return (ft_list_at(begin_list->next, nbr - 1));  
}