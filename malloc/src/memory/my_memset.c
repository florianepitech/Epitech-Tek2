/*
** EPITECH PROJECT, 2021
** B4 - Unix Prog. - Memory
** File description:
** Malloc
*/

#include "malloc.h"
#include "memory.h"

void my_memset(void *ptr, char c, int size)
{
    char *addr = (char*)ptr;
    int i = 0;

    while (i < size) {
        *addr = c;
        addr++;
        i++;
    }
}
