#pragma once
#include <raylib.h>
#include <vector>
#include "Projectile.hpp"
class Player{
    public:
        Player();
        ~Player();
        void Draw();
        void MovePlayer();
        void FireProjectile();
        //Vector2 GetMouseAim();
        std::vector<Projectile> projectiles;

    private:
        Texture2D spr_player;
        Vector2 playerPos;
        Vector2 GetMouseAim();
        float speed = 200.0f;
        double lastTimeFired;
        void Animate();
        
};