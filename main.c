#include "raylib.h"
#include <stdio.h>
#include "config.h"
#include "tiles.h"
//x = columns && y = rows
int main(void){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Map-editor-&-pathfinding");
    SetTargetFPS(60);
    Color tiles_color[TYPES_NB] = {FLOOR_GREEN, WALL_GREEN};
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        for(int x = 0; x < SCREEN_WIDTH / TILE_WIDTH; x++){
            for(int y = 0; y < SCREEN_HEIGHT / TILE_WIDTH; y++){
                DrawRectangleLines(x * TILE_WIDTH, y*TILE_WIDTH, TILE_WIDTH, TILE_WIDTH, WHITE);
            }
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}