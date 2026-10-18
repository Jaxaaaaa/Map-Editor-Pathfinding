#ifndef PATHFINDING_H
#define PATHFINDING_H
#include "map.h"
bool bfs(Tile tiles[MAP_COLS][MAP_ROWS], Coords start, Coords target, Coords queue[MAP_COLS*MAP_ROWS], bool visited[MAP_COLS][MAP_ROWS], Coords came_from[MAP_COLS][MAP_ROWS]);

#endif