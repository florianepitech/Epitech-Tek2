/*
** EPITECH PROJECT, 2021
** B4 - Unix Prog. - Memory
** File description:
** Malloc
*/

#include "malloc.h"
#include "memory.h"
#include <stdint.h>

void free(void *ptr)
{
    if (ptr == NULL)
        return;
    void *header = (ptr - HEADER_SIZE);
    m_header_t *metadata = (m_header_t*)header;
    metadata->is_allocated = 0;
}
