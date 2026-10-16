#include "raylib.h"
#include <stdio.h>
#include "config.h"
#include "editor.h"
#include "map.h"
int main(void){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Map-editor-&-pathfinding");
    SetTargetFPS(60);
    Color tiles_color[TYPES_NB] = {FLOOR_GREEN, WALL_GREEN};
    Tile tiles[MAP_COLS][MAP_ROWS];
    init_coords(tiles);
    while (!WindowShouldClose())
    {
        draw_grid(tiles, tiles_color);
        detect_clic(tiles);
        handle_save_load(tiles);
    }
    CloseWindow();
    return 0;
}