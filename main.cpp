#include <iostream>
#include <raylib.h>
#include "Game.hpp"
int main () 
{   
    int windowWidth = 750;
    int windowHeight = 700;
    Color grey = {29, 29, 27, 255};
    const int FPS = 60;
    InitWindow(windowWidth, windowHeight, "Top down RPG");
    Game game;
    SetTargetFPS(FPS);

    while(WindowShouldClose() == false) {

        game.Update();
        game.HandleInputs();
        BeginDrawing();
            ClearBackground(grey);
            game.Draw();
        EndDrawing();
    };

    CloseWindow();
    return 0;
}