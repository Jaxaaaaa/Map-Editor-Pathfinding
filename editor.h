#ifndef EDITOR_H
#define EDITOR_H
#include "raylib.h"
#include "map.h"
#include "config.h"
#include "stdio.h"
#include "state.h"
#include "drawmap.h"
//x = columns && y = rows
//Construire la grille
//Placer les tiles sur la grille en cliquant, clic gauche pour le sol et clic droit pour les murs

void draw_grid(Tile coord[MAP_COLS][MAP_ROWS], Color tiles_color[TYPES_NB]);
void place_tile(int type, Tile tiles[MAP_COLS][MAP_ROWS]);
void detect_clic(Tile tiles[MAP_COLS][MAP_ROWS]);
void handle_save_load(Tile tiles[MAP_COLS][MAP_ROWS]);
State update_editor();
#endif