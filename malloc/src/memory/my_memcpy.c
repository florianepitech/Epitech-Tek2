/*
** EPITECH PROJECT, 2021
** B4 - Unix Prog. - Memory
** File description:
** Malloc
*/

#include "malloc.h"
#include "memory.h"

void my_memcpy(void *dest, void *src, int size)
{
    char *ptr_dest = (char*)dest;
    char *ptr_src = (char*)src;
    int i = 0;

    while (i < size) {
        ptr_dest[i] = ptr_src[i];
        i++;
    }
}
