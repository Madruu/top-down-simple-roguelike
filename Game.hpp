#pragma once
#include "Player.hpp"
#include "Projectile.hpp"
#include "Enemy.hpp"
#include <vector>
class Game{
    public:
        Game();
        ~Game();
        void Draw();
        void Update();
        void HandleInputs();
    private:
        void InitGame();
        void DeleteInactiveProjectiles();
        void UpdateEnemies();
        void DrawEnemies();
        Player player;
        bool run;
        void CreateEnemy(int type, Vector2 position);
        std::vector<Enemy> enemies;
        void CheckCollisionWithEnemy();
        bool CheckCollisionWithTiles();
        Rectangle boxCollision = { 0 };    
        bool collided;
        std::vector<Rectangle> collisionTiles;
};