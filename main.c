#include "raylib.h"
#include <stdio.h>
#include "config.h"
#include "editor.h"
#include "map.h"
#include "state.h"
#include "menu.h"

int main(void){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Map-editor-&-pathfinding");
    SetExitKey(KEY_NULL);
    SetTargetFPS(60);
    State state = MENU;
    Color tiles_color[TYPES_NB] = {FLOOR_GREEN, WALL_GREEN};
    Tile tiles[MAP_COLS][MAP_ROWS];
    init_coords(tiles);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        switch(state){
            case MENU:
                draw_menu();
                state = update_menu();
                break; 
            case EDITOR: 
                draw_grid(tiles, tiles_color);
                detect_clic(tiles);
                handle_save_load(tiles);
                state = update_editor(); 
                break;
            case PATHFINDING:
                break;
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}