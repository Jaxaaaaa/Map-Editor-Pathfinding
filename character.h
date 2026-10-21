#ifndef CHARACTER_H
#define CHARACTER_H
#include "raylib.h"
#include "map.h"
typedef struct {
    Coords position;
    int path_index;
    int move_timer;
    bool moving;
} Zombie; 
void start_moving(Zombie *zombie, Coords start_coords, int tiles_nb);
void move_character(Zombie *zombie, const Coords path[MAP_COLS*MAP_ROWS]);
void draw_character(Texture2D texture, const Coords coords);
#endif