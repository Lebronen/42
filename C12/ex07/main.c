#include <stdio.h>
#include "ft_list.h"
#include <stdlib.h>

t_list  *ft_list_at(t_list *begin_list, unsigned int nbr);

int main()
{
    t_list *elem1;
    t_list *elem2;
    t_list *elem3;

    elem1 = malloc(sizeof(t_list));
    elem2 = malloc(sizeof(t_list));
    elem3 = malloc(sizeof(t_list));
    elem1->data = (void *)42;
    elem2->data = (void *)24;
    elem3->data = (void *)21;
    elem1->next = elem2;
    elem2->next = elem3;
    printf("%ld\n", (long)ft_list_at(elem1, 2)->data);
    free(elem1);
    free(elem2);
    free(elem3);
    return (0);
}