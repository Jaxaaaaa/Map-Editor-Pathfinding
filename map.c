#include "map.h"
#include "stdio.h"

bool is_inside(int x, int y){
    return x >= 0 && x < MAP_COLS && y >= 0 && y < MAP_ROWS ;
}
void init_coords(Tile tiles[MAP_COLS][MAP_ROWS]){
    for (int x = 0; x < MAP_COLS; x++){
        for (int y = 0; y < MAP_ROWS; y++){
            tiles[x][y].tile_type = FLOOR;
        }
    }
}

void save_map(const char *filename, Tile tile[MAP_COLS][MAP_ROWS]){
    FILE *file; 
    file = fopen(filename, "w");
    if( file == NULL){
        printf("Error opening the file\n");
        return;
    }
    fprintf(file, "%d %d\n", MAP_COLS, MAP_ROWS);
    for(int y = 0; y < MAP_ROWS; y++){
        for(int x = 0; x < MAP_COLS; x++){
            fprintf(file, "%d ", tile[x][y].tile_type);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    printf("Enregistre avec succès\n");
}

void load_map(const char *filename, Tile tile[MAP_COLS][MAP_ROWS]){
    FILE *file;
    file = fopen(filename, "r");
    if( file == NULL){
        printf("Error opening the file\n");
        return;
    }
    int cols;
    int rows;
    if(fscanf(file, "%d %d", cols, rows) )
    for(int y = 0; y < MAP_ROWS; y++){
        for(int x = 0; x < MAP_COLS; x++){
            int value;
            fscanf(file, &value);
            tile[MAP_COLS][MAP_ROWS].tile_type = value;
        }
    }


}