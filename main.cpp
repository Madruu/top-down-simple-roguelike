#include <iostream>
#include <raylib.h>
#include "external/raytmx/raytmx.h"
#include "Game.hpp"
int main () 
{   
        int windowWidth = 1280;
        int windowHeight = 720;
        const int FPS = 60;
        InitWindow(windowWidth, windowHeight, "Top down RPG");
        Game game;
        SetTargetFPS(FPS);

        while(WindowShouldClose() == false) {

                game.Update();
                game.HandleInputs();
                BeginDrawing();
                        ClearBackground(BLACK);
                        game.Draw();
                EndDrawing();
        };

        CloseWindow();
        return 0;
}