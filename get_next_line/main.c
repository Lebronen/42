#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    char    str[7];
    //char    *src = "cc";
    int       fichier;
    fichier = open("nl", O_RDONLY);
    char    *res = get_next_line(fichier);
    printf("%s", res);
    close(fichier);
    return (0);
}