/*
** EPITECH PROJECT, 2024
** unit_test
** File description:
** create map
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/setting_up.h"
void redirect (void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (create_map, test_map_creator)
{
    map_t map = create_map("tests/test");
    int index = 0;
    char *expected_map[] = {".o.o...o..........oo..o....o......o....o........o.............o..o.................o.............o..","...........oo..o.o......o..............o...oo..o...o......o.o..oo...............o..oo.........o.....","....o.o.....o....o..oo...................o...oo......o.....o.o........................o......o......","........oo.............o......o..........o.....o..o......o...o.......o...o....o.....................","..o..o..oo..oo......oo.......o......o...o.....o...oo.......o.............oo.o.oo.oo.........o.......","...............o.........o.......o......oo.....o.....o...o............................oo...o........","...o..o.....................o......o.o........o.........o................o......o......o........o...","..o..o........o..o.................o.o....o.....................o..o...........o..........o....oo...",".....oo....oo...............oo.....o.....o....o..o.....oo.o.o..........oo.....................o.....","..................o......ooo.................o...o...o........o.........o............o..o...o...o..."};

    while (index != map.nb_line){
        cr_assert_str_eq(map.tab_map[index], expected_map[index]);
        index++;
    }
    cr_assert_eq(map.nb_line, 10);
    cr_assert_eq(map.nb_column, 100);
    free(map.tab_map);
}
