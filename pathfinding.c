#include "pathfinding.h"

const int dir_x[4] = {0, 0, -1, 1};
const int dir_y[4] = {-1, 1, 0, 0};

bool bfs(Tile tiles[MAP_COLS][MAP_ROWS], Coords start, Coords target, bool visited[MAP_COLS][MAP_ROWS], Coords came_from[MAP_COLS][MAP_ROWS])
{
    for (int x = 0; x < MAP_COLS; x++)
    { // remise de toutes les cases visited à false
        for (int y = 0; y < MAP_ROWS; y++)
        {
            visited[x][y] = false;
        }
    }
    if (start.x == target.x && start.y == target.y)
    {
        return true;
    }
    int read_index = 0;
    int write_index = 0;
    Coords queue[MAP_COLS * MAP_ROWS]; // stock les cases à visiter dans la file d'attente
    queue[write_index] = start;        // on ajoute le start à la queue
    write_index++;
    visited[start.x][start.y] = true;
    while (read_index != write_index)
    {                                       // tant que la queue n'est pas vide
        Coords current = queue[read_index]; // la tile actuelle es t celle à la première position de lecture de la queue
        read_index++;                       // on retire la tile de la queue
        for (int i = 0; i < 4; i++)
        {                                          // on test les 4 voisines de la case actuelle
            int neighbor_x = current.x + dir_x[i]; // le x de la voisine testée de la case actuelle
            int neighbor_y = current.y + dir_y[i]; // le y de la voisine testée de la case actuelle
            if (is_walkable(tiles, neighbor_x, neighbor_y) && !visited[neighbor_x][neighbor_y])
            {                                      // si la voisine n'est pas en dehors de la carte et n'es pas mur et n'est pas déjà visitée
                queue[write_index].x = neighbor_x; // on l'ajoute à la queue
                queue[write_index].y = neighbor_y;
                visited[neighbor_x][neighbor_y] = true;      // on ajoute la voisine à visited pour eviter de la revisiter lors d'une boucle sur les voisines
                came_from[neighbor_x][neighbor_y] = current; // on range les coordonnées de la case actuelle dans la case du voisin
                if (target.x == neighbor_x && target.y == neighbor_y)
                { // si la voisine est la target, on return true et on sort de bfs
                    return true;
                }
                write_index++;
            }
        }
    }
    return false;
}

// construct_path remplit le tableau reversed_path en remontant les cases contenue dans came_from, donc depuis la cible vers le départ puis renvoie le nombre de case dans le chemin
int construct_path(Coords start, Coords target, Coords came_from[MAP_COLS][MAP_ROWS], Coords reversed_path[MAP_COLS * MAP_ROWS])
{
    int tiles_in_path = 0;
    Coords current = target; // la tile actuelle dans la reconstruction du chemin
    while (current.x != start.x || current.y != start.y)
    {                                               // tant que la tile actuelle n'est pas le point de départ
        reversed_path[tiles_in_path].x = current.x; // on ajoute les coordonnées de current à reverse path
        reversed_path[tiles_in_path].y = current.y;
        current = came_from[current.x][current.y]; // on fait avancer current à la case suivante en lisant les coordonées (du point précédent) dans la case actuelle
        tiles_in_path++;
    }
    return tiles_in_path;
}