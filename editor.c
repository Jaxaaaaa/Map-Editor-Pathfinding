#include "editor.h"
#include "raylib.h"
#include "state.h"
State update_editor(){
    if(IsKeyPressed(KEY_ESCAPE)){
        return MENU; 
    }
    else{
        return EDITOR;
    }
}

void draw_grid(Tile tiles[MAP_COLS][MAP_ROWS], Color tiles_color[TYPES_NB]){
    ClearBackground(LIGHTGRAY);
    for(int x = 0; x < SCREEN_WIDTH / TILE_SIZE; x++){
        for(int y = 0; y < SCREEN_HEIGHT / TILE_SIZE; y++){
            if(tiles[x][y].tile_type == FLOOR){
                DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, tiles_color[tiles[x][y].tile_type]);
            }
            else if(tiles[x][y].tile_type == WALL){
                DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, tiles_color[tiles[x][y].tile_type]);
            }
        }
    }
}

void place_tile(int type, Tile tiles[MAP_COLS][MAP_ROWS]){
    int col = GetMouseX() / TILE_SIZE;
    int row = GetMouseY() / TILE_SIZE;
    if(is_inside(col, row)){
        tiles[col][row].tile_type = type;
    }
}

void detect_clic(Tile tiles[MAP_COLS][MAP_ROWS]){
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        place_tile(FLOOR, tiles);
    }
    else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)){
        place_tile(WALL, tiles);
    }
}

void handle_save_load(Tile tiles[MAP_COLS][MAP_ROWS]){
    if(IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_S)){
        save_map("map_1.txt", tiles);
    }
    if(IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_L)){
        load_map("map_1.txt", tiles);
    }
}