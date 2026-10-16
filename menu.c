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
    DrawRectangleGradientV(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, MENU_TOP_GREEN, MENU_BOTTOM_GREEN);
    int editor_txt_lgt = MeasureText("Editeur de carte (espace)", 20); 
    int pathfinding_txt_lgt = MeasureText("Pathfinding (entree)", 20);
    int title_txt_lgt = MeasureText("Map editor & Pathfinding", 40);
    DrawText("Map editor & Pathfinding", (SCREEN_WIDTH/2) - (title_txt_lgt/2), SCREEN_HEIGHT/2+-100, 50, MENU_TITLE_COLOR);
    DrawText("Editeur de carte (espace)", (SCREEN_WIDTH/2) - (editor_txt_lgt/2), SCREEN_HEIGHT/2-10, 30, MENU_TEXT_COLOR);
    DrawText("Pathfinding (entree)", (SCREEN_WIDTH/2) - (pathfinding_txt_lgt/2), SCREEN_HEIGHT/2+30, 30, MENU_TEXT_COLOR);
}

