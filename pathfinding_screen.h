#ifndef PATHFINDING_H
#define PATHFINDING_H
#include "map.h"
#include "drawmap.h"
#include "stdio.h"
//il me faut une fonction pour placer le start et la target
typedef struct{
    Coords start;
    Coords target;
    bool start_placed;
    bool target_placed;
    bool visited[MAP_COLS][MAP_ROWS]; //stock les cases visitées par l'algo BFS
    Coords came_from[MAP_COLS][MAP_ROWS]; //stock les cases d'ou l'on est venu pour trouver la targer via BFS
} PathfindingScreen;

void handle_pf_clicks(PathfindingScreen *pathfinding_screen, Tile tiles[MAP_COLS][MAP_ROWS]);
void draw_pf_components(const PathfindingScreen *pathfinding_screen);

#endif