#pragma once
#include "Player.hpp"
#include <raylib.h>

class CameraGame {
    public: 
        CameraGame();
        ~CameraGame();
        void Update(const Vector2& targetPosition);
        void Begin();
        void End();
    private:
        Camera2D camera;
        Player player;
        int frameHeight = 32;
        int frameWidth = 160;
        float smoothSpeed = 4.0f;
};