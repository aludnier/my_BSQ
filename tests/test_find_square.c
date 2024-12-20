/*
** EPITECH PROJECT, 2024
** unit_test
** File description:
** find_square
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/setting_up.h"

Test(copy_map, copy_an_map)
{
    char *tab_map[] = {"...o...ooo","...ooo.oo.",".o..oo.oo.","ooo...oo.."};
    map_t map = {4, 10, tab_map};
    char **dest = malloc(sizeof(char *) * (map.nb_line + 2));
    int index = 0;

    copy_map(map, dest);
    while (index != map.nb_line){
        cr_assert_str_eq(map.tab_map[index], dest[index]);
        index++;
    }
    free(dest);
}

Test (is_greater, is_square_greater_true)
{
    square_t square = {5, 7, 9};
    int x = 6;

    is_greater(&square, &x, 10, '9');
    cr_assert_eq(square.size, 9);
    cr_assert_eq(square.x, 6);
    cr_assert_eq(square.y, 10);
}

Test (is_greater, is_square_greater_false)
{
    square_t square = {5, 7, 9};
    int x = 6;

    is_greater(&square, &x, 10, '2');
    cr_assert_eq(square.size, 5);
    cr_assert_eq(square.x, 7);
    cr_assert_eq(square.y, 9);
}

Test(find_greatest_square, find_greatest_square_in_a_map)
{
    char *tab_map[] = {"...o...ooo",
                       "...ooo.oo.",
                       ".oo....oo.",
                       "oo....oo..",
                       ".o....oo.."};
    map_t map = {5, 10, tab_map};
    int index = 0;
    char *map_cp[] = {"221o111ooo",
                      "111ooo1oo1",
                      "1oo3211oo1",
                      "oo2221oo21",
                      "1o1111oo11"};
    square_t great_square = {3, 3, 2};
    square_t square = {0, 0, 0};

    square= find_greatest_square(map, map_cp);
    cr_assert_eq(square.x, great_square.x);
    cr_assert_eq(square.y, great_square.y);
    cr_assert_eq(square.size, great_square.size);
}

Test (put_size, change_size)
{
    char *tab_map[] = {"...o...ooo",
		       "...ooo.oo.",
                       ".oo....oo.",
                       "oo....oo..",
                       ".o....oo.."};
    map_t map = {4, 10, tab_map};
    char **map_cp = malloc(sizeof(char *) * (map.nb_line + 2));
    int index = 0;
    square_t square = {8, 1, 1};
    
    copy_map(map, map_cp);
    put_size(map_cp, square);
    cr_assert_str_eq(map_cp[1], ".8.ooo.oo.");
    free(map_cp);
}
