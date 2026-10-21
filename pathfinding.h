#ifndef PATHFINDING_H
#define PATHFINDING_H
#include "map.h"
bool bfs(Tile tiles[MAP_COLS][MAP_ROWS], Coords start, Coords target, bool visited[MAP_COLS][MAP_ROWS], Coords came_from[MAP_COLS][MAP_ROWS]);
int construct_path(Coords start, Coords target, Coords came_from[MAP_COLS][MAP_ROWS], Coords reversed_path[MAP_COLS * MAP_ROWS]);
#endif