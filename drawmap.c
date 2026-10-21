#include "drawmap.h"
#include "raylib.h"

bool get_mouse_cell(Coords *cell)
{ // return le x et y ce la cellule sous la souris si ils ne sortent pas de l'écran
        cell->x = GetMouseX() / TILE_SIZE;
        cell->y = GetMouseY() / TILE_SIZE;
        return is_inside(cell->x, cell->y);
}