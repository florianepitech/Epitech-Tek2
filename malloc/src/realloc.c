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

void *realloc(void *ptr, size_t size)
{

    if (ptr == NULL)
        return malloc(size);
    void *header = ptr - HEADER_SIZE;
    if (((m_header_t*)header)->size >= size)
        return ptr;

    void *result = malloc(size);
    header = result - HEADER_SIZE;
    result = memset(result, 0, ((m_header_t*)header)->size - HEADER_SIZE);
    result = memcpy(result, ptr, ((m_header_t*)header)->size - HEADER_SIZE);
    return (result);
}
