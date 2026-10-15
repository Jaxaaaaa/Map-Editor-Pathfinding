#ifndef EDITOR_H
#define EDITOR_H
#include "raylib.h"
#include "map.h"
#include "config.h"
//x = columns && y = rows
//Construire la grille
//Placer les tiles sur la grille en cliquant, clic gauche pour le sol et clic droit pour les murs

void draw_grid(Coords coord[SCREEN_WIDTH/TILE_WIDTH][SCREEN_HEIGHT/TILE_WIDTH], Color tiles_color[TYPES_NB]);
void place_tile(int type, Coords coords[SCREEN_WIDTH/TILE_WIDTH][SCREEN_HEIGHT/TILE_WIDTH]);
void detect_clic(Coords coords[SCREEN_WIDTH/TILE_WIDTH][SCREEN_HEIGHT/TILE_WIDTH]);
bool is_inside(int x, int y);
#endif