/*
** EPITECH PROJECT, 2021
** B4 - Unix Prog. - Memory
** File description:
** Malloc
*/

#include "malloc.h"
#include "memory.h"
#include <stdint.h>

extern void *first_header;
extern void *last_header;

int calcul_memory_to_allocate(size_t size)
{
    size_t place_remaining = memory_remaining_in_the_last_block();
    if (size > place_remaining) {
        size_t memory_to_allow = PAGE_SIZE;
        while (memory_to_allow < (size - place_remaining))
            memory_to_allow += PAGE_SIZE;
        return memory_to_allow;
    }
    return 0;
}

size_t get_memory_used(void)
{
    if (first_header == NULL || last_header == NULL)
        return 0;
    return ((intptr_t)sbrk(0) - (intptr_t)first_header);
}

size_t get_block_used(void)
{
    if (first_header == NULL || last_header == NULL)
        return 0;
    int used_memory = get_memory_used();
    if (used_memory == 0)
        return 0;
    if (used_memory <= PAGE_SIZE)
        return 1;
    int result = used_memory / PAGE_SIZE;
    if (result % PAGE_SIZE != 0)
        result++;
    return result;
}

size_t memory_remaining_in_the_last_block(void)
{
    if (last_header == NULL || first_header == NULL)
        return 0;
    intptr_t break_memory = (intptr_t)sbrk(0);
    intptr_t end_last_header = (intptr_t)last_header;
    end_last_header += ((m_header_t*)last_header)->size;

    return (size_t)(break_memory - end_last_header);
}
