/*
** EPITECH PROJECT, 2021
** B4 - Unix Prog. - Memory
** File description:
** Malloc
*/

#include "malloc.h"
#include <stdint.h>

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    if (ptr == NULL)
        return malloc(nmemb * size);
    size_t nmemb_size = (size_t)(nmemb * size);
    return (realloc(ptr, nmemb_size));
}
