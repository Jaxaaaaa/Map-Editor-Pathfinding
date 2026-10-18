#include "pathfinding.h"

const int dir_x[4] = {0, 0 , -1, 1};
const int dir_y[4] = {-1, 1, 0, 0};


bool bfs(Tile tiles[MAP_COLS][MAP_ROWS], Coords start, Coords target, bool visited[MAP_COLS][MAP_ROWS], Coords came_from[MAP_COLS][MAP_ROWS]){
    for(int x = 0; x <MAP_COLS; x++){ //remise de toutes les cases visited à false
        for(int y = 0; y < MAP_ROWS; y++){
            visited[x][y] = false;
        }
    }
    if(start.x == target.x && start.y == target.y){
        return true;
    }
    int read_index = 0;
    int write_index = 0;
    Coords queue[MAP_COLS*MAP_ROWS]; //stock les cases à visiter dans la file d'attente
    queue[write_index] = start;  //on ajoute le start à la queue
    write_index++;
    visited[start.x][start.y] = true;
    while(read_index != write_index){ //tant que la queue n'est pas vide
        Coords current = queue[read_index]; //la tile actuelle est celle à la première position de lecture de la queue
        read_index++; //on retire la tile de la queue
        for(int i = 0; i < 4; i++){ //on test les 4 voisines de la case actuelle
            int neighbor_x = current.x + dir_x[i]; //le x de la voisine testée de la case actuelle
            int neighbor_y = current.y + dir_y[i]; //le y de la voisine testée de la case actuelle
            if(is_walkable(tiles, neighbor_x, neighbor_y) && !visited[neighbor_x][neighbor_y]){ //si la voisine n'est pas en dehors de la carte et n'es pas mur et n'est pas déjà visitée
                queue[write_index].x = neighbor_x; //on l'ajoute à la queue
                queue[write_index].y = neighbor_y;
                visited[neighbor_x][neighbor_y] = true; //on ajoute la voisine à visited pour eviter de la revisiter lors d'une boucle sur les voisines
                came_from[neighbor_x][neighbor_y] = current; //on ajoute les coordonnées (la fleche) de la case actuelles à la position de la voisine, pour qu'on puisse savoir d'ou l'on vient 
                if(target.x == neighbor_x && target.y == neighbor_y){ //si la voisine est la target, on return true et on sort de bfs
                    return true;
                }
                write_index++;
            }
        }
    }
    return false;
}