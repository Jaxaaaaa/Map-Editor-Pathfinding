#include "pathfinding_screen.h"
#include "raylib.h"
#include "drawmap.h"
#include "pathfinding.h"

State update_pf_screen()
{
    if (IsKeyPressed(KEY_ESCAPE))
    {
        return MENU;
    }
    else
    {
        return PATHFINDING;
    }
}

void handle_pf_clicks(PathfindingScreen *pathfinding_screen, Tile tiles[MAP_COLS][MAP_ROWS])
{
    Coords cell;
    if (get_mouse_cell(&cell) && tiles[cell.x][cell.y].tile_type != WALL)
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (pathfinding_screen->start_placed && pathfinding_screen->start.x == cell.x && pathfinding_screen->start.y == cell.y)
            {
                pathfinding_screen->start_placed = false;
            }
            else if (!pathfinding_screen->start_placed)
            {
                pathfinding_screen->start = cell;
                pathfinding_screen->start_placed = true;
            }
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        {
            if (pathfinding_screen->target_placed && pathfinding_screen->target.x == cell.x && pathfinding_screen->target.y == cell.y)
            {
                pathfinding_screen->target_placed = false;
            }
            else if (!pathfinding_screen->target_placed)
            {
                pathfinding_screen->target = cell;
                pathfinding_screen->target_placed = true;
            }
        }
    }
}

void draw_pf_components(const PathfindingScreen *pathfinding_screen)
{
    if (pathfinding_screen->start_placed)
    {
        DrawRectangle(pathfinding_screen->start.x * TILE_SIZE, pathfinding_screen->start.y * TILE_SIZE, TILE_SIZE, TILE_SIZE, GREEN);
    }
    if (pathfinding_screen->target_placed)
    {
        DrawRectangle(pathfinding_screen->target.x * TILE_SIZE, pathfinding_screen->target.y * TILE_SIZE, TILE_SIZE, TILE_SIZE, RED);
    }
}

void start_bfs(PathfindingScreen *pathfinding_screen, Tile tiles[MAP_COLS][MAP_ROWS])
{
    if (!pathfinding_screen->start_placed || !pathfinding_screen->target_placed)
    { // si la case départ ou la case target ne sont pas placée, pathfound est false
        pathfinding_screen->pathfound = false;
        pathfinding_screen->tiles_in_path = 0;
        pathfinding_screen->zombie.moving = false;
    }
    if (IsKeyPressed(KEY_SPACE) && pathfinding_screen->start_placed && pathfinding_screen->target_placed)
    {
        pathfinding_screen->pathfound = bfs(tiles, pathfinding_screen->start, pathfinding_screen->target, pathfinding_screen->visited, pathfinding_screen->came_from);
        if (pathfinding_screen->pathfound)
        {
            pathfinding_screen->tiles_in_path = construct_path(pathfinding_screen->start, pathfinding_screen->target, pathfinding_screen->came_from, pathfinding_screen->reversed_path);
            start_moving(&pathfinding_screen->zombie, pathfinding_screen->start, pathfinding_screen->tiles_in_path);
        }
        else
        {
            pathfinding_screen->tiles_in_path = 0;     // si bfs echoue, remise à 0 de tiles_in_path
            pathfinding_screen->zombie.moving = false; // et le moving de zombie passe à false
        }
    }
}

void draw_visited_tiles(const PathfindingScreen *pathfinding_screen)
{
    for (int x = 0; x < MAP_COLS; x++)
    {
        for (int y = 0; y < MAP_ROWS; y++)
        {
            if (pathfinding_screen->visited[x][y] == true)
            {
                DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, Fade(BLUE, 0.4f));
            }
        }
    }
}

void draw_path(const PathfindingScreen *pathfinding_screen)
{
    for (int i = 0; i < pathfinding_screen->tiles_in_path; i++)
    {
        DrawRectangle(pathfinding_screen->reversed_path[i].x * TILE_SIZE, pathfinding_screen->reversed_path[i].y * TILE_SIZE, TILE_SIZE, TILE_SIZE, ORANGE);
    }
}