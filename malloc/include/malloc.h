/*
** EPITECH PROJECT, 2021
** B4 - Unix Prog. - Memory
** File description:
** Malloc
*/

#ifndef malloc_HEADER
    #define malloc_HEADER

    #include <unistd.h>

typedef struct m_header {
    char    is_allocated;
    size_t  size;
} m_header_t;

//malloc functions
void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

    #define ALIGNMENT 8
    #define ALIGN_SIZE(size) (((size) + (ALIGNMENT-1)) & ~(ALIGNMENT-1))
    #define HEADER_SIZE (ALIGN_SIZE(sizeof(struct m_header)))
    #define PAGE_SIZE getpagesize() * 2

#endif
