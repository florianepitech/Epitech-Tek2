/*
** EPITECH PROJECT, 2021
** B4 - Unix Prog. - Memory
** File description:
** Malloc
*/

#ifndef MEMORY_HEADER
    #define MEMORY_HEADER

    #include "malloc.h"
    #include "memory.h"
    #include <unistd.h>

//memory_utils.c
int calcul_memory_to_allocate(size_t size);
size_t get_memory_used(void);
size_t get_block_used(void);
size_t memory_remaining_in_the_last_block(void);

//my_memcpy.c
void my_memcpy(void *dest, void *src, int size);

//my_memset.c
void my_memset(void *ptr, char c, int size);

#endif
