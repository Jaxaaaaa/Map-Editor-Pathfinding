#include "menu.h"
#include "config.h"
#include "map.h"
State update_menu(){
    if(IsKeyPressed(KEY_SPACE)){
        return EDITOR;
    }
    if(IsKeyPressed(KEY_ENTER)){
        return PATHFINDING;
    }
    else{
        return MENU; 
    }
}
void draw_menu(){
    BeginDrawing();
    DrawRectangleGradientV(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, MENU_TOP_GREEN, MENU_BOTTOM_GREEN);
    DrawText(TextFormat("Editeur de carte (espace)"), 0, SCREEN_HEIGHT/2-10, 20, MENU_TEXT_COLOR);
    DrawText(TextFormat("Pathfinding (entree)"), 0, SCREEN_HEIGHT/2+200, 20, MENU_TEXT_COLOR);
    EndDrawing();
}

