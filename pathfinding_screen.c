#include "pathfinding_screen.h"
#include "raylib.h"
#include "drawmap.h"

void handle_pf_clicks(PathfindingScreen *pathfinding_screen, Tile tiles[MAP_COLS][MAP_ROWS]){
    Coords cell;
    if(get_mouse_cell(&cell) && tiles[cell.x][cell.y].tile_type != WALL  ){
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(pathfinding_screen->start_placed && pathfinding_screen->start.x == cell.x && pathfinding_screen->start.y == cell.y){
                pathfinding_screen->start_placed = false;
            }
            else if(!pathfinding_screen->start_placed){
                pathfinding_screen->start = cell;
                pathfinding_screen->start_placed = true;
            }
        }
        if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
            if(pathfinding_screen->target_placed && pathfinding_screen->target.x == cell.x && pathfinding_screen->target.y == cell.y){
                pathfinding_screen->target_placed = false;
            }
            else if(!pathfinding_screen->target_placed){
                pathfinding_screen->target = cell;
                pathfinding_screen->target_placed = true;
            }
        }
    }
}

void draw_pf_components(PathfindingScreen pathfinding_screen){
    if(pathfinding_screen->start_placed){
        DrawRectangle(pathfinding_screen->start.x * TILE_SIZE, pathfinding_screen->start.y * TILE_SIZE, TILE_SIZE, TILE_SIZE, GREEN);
    }
    if(pathfinding_screen->target_placed){
        DrawRectangle(pathfinding_screen->target.x * TILE_SIZE, pathfinding_screen->target.y * TILE_SIZE, TILE_SIZE, TILE_SIZE, RED);
    }
}