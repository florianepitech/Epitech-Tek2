/*
** EPITECH PROJECT, 2021
** B4 - Unix Prog. - Memory
** File description:
** Malloc
*/

#include "malloc.h"
#include "memory.h"
#include <unistd.h>
#include <stdint.h>

void *first_header = NULL;
void *last_header = NULL;

static m_header_t *find_best_fit(size_t size);
static void set_header(void *header, size_t size);

void *malloc(size_t size)
{
    size_t blk_size = ALIGN_SIZE(size + HEADER_SIZE);

    void *header = find_best_fit(size);
    if (header == NULL) {
        size_t memory_to_allocate = calcul_memory_to_allocate(blk_size);

        if (memory_to_allocate != 0 && last_header == NULL)
            header = sbrk(memory_to_allocate);
        if (memory_to_allocate != 0 && last_header != NULL)
            sbrk(memory_to_allocate);
        if (last_header != NULL)
            header = last_header + ((m_header_t*)last_header)->size;
    }
    set_header(header, blk_size);

    if (first_header == NULL)
        first_header = header;
    last_header = header;
    return (header + HEADER_SIZE);
}

/*
 $      STATIC FUNCTION
 */

static m_header_t *find_best_fit(size_t size)
{
    if (first_header == NULL || last_header == NULL)
        return NULL;
    void *temp_header = first_header;
    m_header_t *result = NULL;
    while ((intptr_t)temp_header <= (intptr_t)last_header) {
        if (((m_header_t*)temp_header)->is_allocated == 1
            || ((m_header_t*)temp_header)->size < size) {
            temp_header += ((m_header_t*)temp_header)->size;
            continue;
        }
        if (((m_header_t*)temp_header)->size == size)
            return temp_header;
        if (result == NULL) {
            result = temp_header;
            temp_header += ((m_header_t*)temp_header)->size;
            continue;
        }
        if (result->size > ((m_header_t*)temp_header)->size)
            result = temp_header;
        temp_header += ((m_header_t*)temp_header)->size;
    }
    return result;
}

static void set_header(void *header, size_t size)
{
    m_header_t *metadata = header;
    metadata->is_allocated = 1;
    metadata->size = size;
}
