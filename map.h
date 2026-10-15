#ifndef MAP_H
#define MAP_H
#include "config.h"
#include "stdbool.h"
#define MAP_COLS 95
#define MAP_ROWS 50

//j'ai besoin d'une struct coords
//J'ai besoin d'un enum Tile_type et d'un array color, l'array est déclaré dans le main

typedef enum{
    FLOOR,
    WALL,
    TYPES_NB,
} Tile_type;

typedef struct{
    int tile_type;
} Coords;
bool is_inside(int x, int y);
void init_coords(Coords coords[MAP_COLS][MAP_ROWS]);
#endif