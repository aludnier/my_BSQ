/*
** EPITECH PROJECT, 2024
** square macro
** File description:
** define
*/

#include <stdbool.h>

#ifndef SQUARE
    #define SQUARE
    #define IS_POINT(c) ((c) == ('.') ? (true) : (false))

typedef struct {
    int x;
    int y;
} coordinates_t;

typedef struct {
    unsigned int size;
    unsigned int x;
    unsigned int y;
} square_t;

typedef struct {
    int nb_line;
    int nb_column;
    char **tab_map;
} map_t;

map_t create_map(char *file_path);
int get_nb_line(char *filepath);
void find_square(map_t map);
square_t check_square(char **map_cp, int x, int y, int nb_line);
void replace_square(char **map, square_t square, char replace_char);
int check_size_up(char **map_cp, coordinates_t co, int size, int nb_line);
void create_array_map(char **tab_map, char *str_map, int index);
map_t generate_map(int size, char *patch);
bool verify_create(char *path_file);
bool verify_generate(char *size, char *patch);
void copy_map(map_t map, char **dest);
square_t find_greatest_square(map_t map, char **map_cp);
void is_greater(square_t *great_square, int *x, int y, char char_size);
void put_size(char **map_cp, square_t square);
bool verify_nb_line(char **tab_map, int nb_line_expected);

#endif
