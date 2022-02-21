/*
** EPITECH PROJECT, 2021
** B4 - Unix Prog. - Memory
** File description:
** Malloc
*/

#include <criterion/criterion.h>
#include "malloc.h"

Test(malloc, test_malloc_str)
{
    char *str1 = malloc(sizeof(char) * 6);
    for (int i = 0; i < 5; i++)
        str1[i] = 'a' + i;
    str1[5] = 0;

    char *str2 = malloc(sizeof(char) * 4);
    for (int i = 0; i < 2; i++)
        str2[i] = 'a' + i;
    str2[3] = 0;

    free(str1);
    free(str2);
    
    cr_assert(1);
}


Test(malloc, test_malloc_int)
{
    int *i = malloc(sizeof(int));
    *i = 1;
    char verifier = (*i == 1);
    free(i);
    cr_assert(verifier);
}

Test(malloc, test_malloc_null)
{
    void *ptr = malloc(0);
    cr_assert(ptr != NULL);
}
