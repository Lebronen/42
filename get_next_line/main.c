#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    char    str[3];
    int       fichier;
    fichier = open("fichier.txt", O_RDONLY);
    char    *res = get_next_line(fichier);
    printf("%s", res);
    //printf("%ld\n", read(fichier, str, 3));
    //printf("%ld", read(fichier, str, 3));
    close(fichier);
    return (0);
}