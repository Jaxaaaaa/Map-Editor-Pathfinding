#ifndef EDITOR_H
#define EDITOR_H
#include "raylib.h"
#include "map.h"
#include "config.h"
//x = columns && y = rows
//Construire la grille
//Placer les tiles sur la grille en cliquant, clic gauche pour le sol et clic droit pour les murs

void draw_grid(Coords coord[MAP_COLS][MAP_ROWS], Color tiles_color[TYPES_NB]);
void place_tile(int type, Coords coords[MAP_COLS][MAP_ROWS]);
void detect_clic(Coords coords[MAP_COLS][MAP_ROWS]);
#endif