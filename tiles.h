#ifndef TILES_H
#define TILES_H
#include "raylib.h"
#include "config.h"
//J'ai besoin d'un enum Tile_type et d'un array color, l'array est déclaré dans le main
//J'ai besoin d'une fonction pour placer le sol et les murs

typedef enum{
    FLOOR,
    WALL,
    TYPES_NB,
} Tile_type;

void place_tiles();

#endif