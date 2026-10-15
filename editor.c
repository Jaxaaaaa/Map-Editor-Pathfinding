#include "editor.h"
#include "raylib.h"



void draw_grid(Coords coords[SCREEN_WIDTH/TILE_WIDTH][SCREEN_HEIGHT/TILE_WIDTH], Color tiles_color[TYPES_NB]){
    BeginDrawing();
    ClearBackground(LIGHTGRAY);
    for(int x = 0; x < SCREEN_WIDTH / TILE_WIDTH; x++){
        for(int y = 0; y < SCREEN_HEIGHT / TILE_WIDTH; y++){
            if(coords[x][y].tile_type == FLOOR){
                DrawRectangle(coords[x][y].coord_x, coords[x][y].coord_y, TILE_WIDTH, TILE_WIDTH, tiles_color[coords[x][y].tile_type]);
            }
            else if(coords[x][y].tile_type == WALL){
                DrawRectangle(coords[x][y].coord_x, coords[x][y].coord_y, TILE_WIDTH, TILE_WIDTH, tiles_color[coords[x][y].tile_type]);
            }
        }
    }
    EndDrawing();
}

void place_tile(int type, Coords coords[SCREEN_WIDTH/TILE_WIDTH][SCREEN_HEIGHT/TILE_WIDTH]){
    int mouse_x = GetMouseX() / TILE_WIDTH;
    int mouse_y = GetMouseY() / TILE_WIDTH;
    coords[mouse_x][mouse_y].coord_x = mouse_x * TILE_WIDTH;
    coords[mouse_x][mouse_y].coord_y = mouse_y * TILE_WIDTH;
    coords[mouse_x][mouse_y].tile_type = type;

}

void detect_clic(Coords coords[SCREEN_WIDTH/TILE_WIDTH][SCREEN_HEIGHT/TILE_WIDTH]){
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        place_tile(FLOOR, coords);
    }
    else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)){
        place_tile(WALL, coords);
    }
}