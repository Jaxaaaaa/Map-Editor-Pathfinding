#include "character.h"
#include "config.h"

void draw_character(Texture2D texture, Coords coords)
{
    Rectangle zombie_source = {0, 0, CHARACTER_ZOMBIE_WIDTH, CHARACTER_ZOMBIE_HEIGHT};
    float display_h = TILE_SIZE * 3;                   // on décide de la hauteur voulue
    float scale = display_h / CHARACTER_ZOMBIE_HEIGHT; // on calcule le facteur de réduction en divisant la taille voulue par la taille originale
    float display_w = CHARACTER_ZOMBIE_WIDTH * scale;  // on obtient la largeur en la multipliant par le facteur

    float cell_x = coords.x * TILE_SIZE; // on designe le coin haut gauche de la tile ciblée en pixels
    float cell_y = coords.y * TILE_SIZE;

    Rectangle dest = {// on créer la destination du rectangle
                      cell_x + TILE_SIZE / 2 - display_w / 2,
                      cell_y + TILE_SIZE / 2 - display_h,
                      display_w,
                      display_h};
    DrawTexturePro(texture, zombie_source, dest, (Vector2){0, 0}, 0.0f, WHITE);
}

void start_moving(Zombie *zombie, Coords start_coords, int tiles_nb)
{
    zombie->position = start_coords;
    zombie->path_index = tiles_nb - 1;
    zombie->move_timer = CHARACTER_MOVE_DELAY;
    if (tiles_nb > 0)
    {
        zombie->moving = true;
    }
    else
    {
        zombie->moving = false;
    }
}

void move_character(Zombie *zombie, const Coords path[MAP_COLS * MAP_ROWS])
{
    if (zombie->moving)
    {
        zombie->move_timer--; // si le zombie bouge on réduit le timer
        if (zombie->move_timer <= 0)
        {                                                // si le timer est à zero
            zombie->position = path[zombie->path_index]; // on fait avancer la position du zombie
            if (zombie->path_index == 0)
            {
                zombie->moving = false; // si il est arrivé il arrete de bouger
            }
            else
            { // si il n'est pas arrivé, on diminue l'index
                zombie->path_index--;
            }
            zombie->move_timer = CHARACTER_MOVE_DELAY;
        }
    }
}