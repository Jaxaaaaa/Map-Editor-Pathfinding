#include "raylib.h"
#include <stdio.h>
#include "config.h"
#include "editor.h"
#include "map.h"
int main(void){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Map-editor-&-pathfinding");
    SetTargetFPS(60);
    Color tiles_color[TYPES_NB] = {FLOOR_GREEN, WALL_GREEN};
    Coords coords[MAP_COLS][MAP_ROWS];
    init_coords(coords);
    while (!WindowShouldClose())
    {
        draw_grid(coords, tiles_color);
        detect_clic(coords);
    }
    CloseWindow();
    return 0;
}