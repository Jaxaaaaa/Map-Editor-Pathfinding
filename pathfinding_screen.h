#ifndef PATHFINDING_H
#define PATHFINDING_H
#include "map.h"
#include "drawmap.h"
//il me faut une fonction pour placer le start et la target
typedef struct{
    Coords start;
    Coords target;
    bool start_placed;
    bool target_placed;
} PathfindingScreen;

void handle_pf_clicks(PathfindingScreen *pathfinding_screen, Tile tiles[MAP_COLS][MAP_ROWS]);
void draw_pf_components(PathfindingScreen pathfinding_screen);

#endif