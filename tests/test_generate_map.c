/*
** EPITECH PROJECT, 2024
** unit test
** File description:
** generate_map
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/setting_up.h"

Test(generate_map, generate_map_from_patch)
{
    map_t map = generate_map(6, "...oo..o.");
    int index = 0;
    char *expected[] = {"...oo.",".o....","oo..o.","...oo.",".o....","oo..o."};

    while (index != map.nb_line){
        cr_assert_str_eq(map.tab_map[index], expected[index]);
        index++;
    }
    cr_assert_eq(map.nb_line, 6);
    cr_assert_eq(map.nb_column, 6);
    free(map.tab_map);
}
