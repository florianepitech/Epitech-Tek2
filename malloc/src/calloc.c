/*
** EPITECH PROJECT, 2021
** B4 - Unix Prog. - Memory
** File description:
** Malloc
*/

#include "malloc.h"
#include "memory.h"
#include <string.h>
#include <unistd.h>

void *calloc(size_t nmemb, size_t size)
{
    void *result = malloc(nmemb * size);
    void *header = result - HEADER_SIZE;
    result = memset(result, 0, ((m_header_t*)header)->size - HEADER_SIZE);
    return result;
}
