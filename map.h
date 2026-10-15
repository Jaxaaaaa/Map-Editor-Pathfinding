#ifndef MAP_H
#define MAP_H
#include "config.h"
#define MAP_COLS 190
#define MAP_ROWS 100
//j'ai besoin d'une struct coords
//J'ai besoin d'un enum Tile_type et d'un array color, l'array est déclaré dans le main

typedef enum{
    FLOOR,
    WALL,
    TYPES_NB,
} Tile_type;

typedef struct{
    int coord_x;
    int coord_y;
    int tile_type;
} Coords;
bool is_inside(int x, int y);
void init_coords(Coords coords[SCREEN_WIDTH/TILE_WIDTH][SCREEN_HEIGHT/TILE_WIDTH]);
#endif