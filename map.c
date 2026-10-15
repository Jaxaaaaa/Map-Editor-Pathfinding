#include "map.h"

void init_coords(Coords coords[SCREEN_WIDTH/TILE_WIDTH][SCREEN_HEIGHT/TILE_WIDTH]){
    for (int x = 0; x < SCREEN_WIDTH/TILE_WIDTH; x++){
        for (int y = 0; y < SCREEN_HEIGHT/TILE_WIDTH; y++){
            coords[x][y].tile_type = FLOOR;
            coords[x][y].coord_x = x * TILE_WIDTH;
            coords[x][y].coord_y = y * TILE_WIDTH;
        }
    }
}