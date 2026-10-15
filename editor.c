#include "editor.h"
#include "raylib.h"



void draw_grid(Coords coords[MAP_COLS][MAP_ROWS], Color tiles_color[TYPES_NB]){
    BeginDrawing();
    ClearBackground(LIGHTGRAY);
    for(int x = 0; x < SCREEN_WIDTH / TILE_SIZE; x++){
        for(int y = 0; y < SCREEN_HEIGHT / TILE_SIZE; y++){
            if(coords[x][y].tile_type == FLOOR){
                DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, tiles_color[coords[x][y].tile_type]);
            }
            else if(coords[x][y].tile_type == WALL){
                DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, tiles_color[coords[x][y].tile_type]);
            }
        }
    }
    EndDrawing();
}

void place_tile(int type, Coords coords[MAP_COLS][MAP_ROWS]){
    int col = GetMouseX() / TILE_SIZE;
    int row = GetMouseY() / TILE_SIZE;
    if(is_inside(col, row)){
        coords[col][row].tile_type = type;
    }
}

void detect_clic(Coords coords[MAP_COLS][MAP_ROWS]){
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        place_tile(FLOOR, coords);
    }
    else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)){
        place_tile(WALL, coords);
    }
}