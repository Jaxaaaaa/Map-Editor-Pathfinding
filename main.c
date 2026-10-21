#include "raylib.h"
#include <stdio.h>
#include "config.h"
#include "editor.h"
#include "map.h"
#include "state.h"
#include "menu.h"
#include "pathfinding_screen.h"
#include "character.h"
int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Map-editor-&-pathfinding");
    Texture2D zombie_texture = LoadTexture("assets/Character_Zombie3.png");
    SetExitKey(KEY_NULL);
    SetTargetFPS(60);
    State state = MENU;
    Color tiles_color[TYPES_NB] = {FLOOR_GREEN, WALL_GREEN};
    Tile tiles[MAP_COLS][MAP_ROWS];
    PathfindingScreen pathfinding_screen = {0};
    init_coords(tiles);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        switch (state)
        {
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
            draw_grid(tiles, tiles_color);
            // draw_visited_tiles(&pathfinding_screen);
            // draw_path(&pathfinding_screen);
            handle_save_load(tiles);
            handle_pf_clicks(&pathfinding_screen, tiles);
            draw_pf_components(&pathfinding_screen);
            start_bfs(&pathfinding_screen, tiles);
            move_character(&pathfinding_screen.zombie, pathfinding_screen.reversed_path);
            draw_character(zombie_texture, pathfinding_screen.zombie.position);
            state = update_pf_screen();
        }
        EndDrawing();
    }
    UnloadTexture(zombie_texture);
    CloseWindow();
    return 0;
}