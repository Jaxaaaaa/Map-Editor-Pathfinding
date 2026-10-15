#include "map.h"

bool is_inside(int x, int y){
    return x >= 0 && x < MAP_COLS && y >= 0 && y < MAP_ROWS ;
}
void init_coords(Coords coords[MAP_COLS][MAP_ROWS]){
    for (int x = 0; x < MAP_COLS; x++){
        for (int y = 0; y < MAP_ROWS; y++){
            coords[x][y].tile_type = FLOOR;
        }
    }
}