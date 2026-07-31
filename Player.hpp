#pragma once
#include <raylib.h>
#include <vector>
#include "Projectile.hpp"

class Player{
    public:
        Player();
        ~Player();
        void Draw();
        void FireProjectile();
        void MovePlayer();
        Vector2 GetPosition() const;
        std::vector<Projectile> projectiles;
        Rectangle GetRect();
        void HandleInput();
        void TakeDamage(int damage, const Vector2& enemySourcePosition);
        void SavePosition();
        void RestorePosition();
    private:
        Texture2D spr_player;
        Vector2 playerPos;
        Vector2 GetMouseAim();
        float speed = 200.0f;
        double lastTimeFired;
        Vector2 oldPlayerPosition;
        int health = 10;
        int knockBackPower = 2000;
        Vector2 knockBackVelocity = { 0.0f, 0.0f };
        void Animate();
        Vector2 input = { 0.0f, 0.0f };
};  