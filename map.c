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
    fscanf(file, "%d %d", &cols, &rows);
    if(cols != MAP_COLS || rows != MAP_ROWS){
        printf("Header error\n");
        fclose(file);
        return;
    }
    for(int y = 0; y < MAP_ROWS; y++){
        for(int x = 0; x < MAP_COLS; x++){
            int value;
            fscanf(file, "%d", &value);
            tile[x][y].tile_type = value;
        }
    }
    fclose(file);
    printf("Charge avec succes\n");
}

bool is_walkable(Tile tiles[MAP_COLS][MAP_ROWS], int x, int y){
    return is_inside(x, y) && tiles[x][y].tile_type != WALL;
}