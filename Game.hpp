#pragma once
#include "Player.hpp"
#include "Projectile.hpp"
#include "Enemy.hpp"
#include "CameraGame.hpp"
#include "TileMap.hpp"
#include "SlashAttack.hpp"
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
                CameraGame camera;
                TileMap tileMap;
                bool run;
                void InitTileMap();
                void CreateEnemy(int type, Vector2 position);
                std::vector<Enemy> enemies;
                void CheckCollisionWithEnemy();
                bool CheckCollisionWithTiles();
                Rectangle boxCollision = { 0 };  
                Rectangle tileSetGround;  
                bool collided;
                std::vector<SlashAttack> slashes;
                std::vector<Rectangle> collisionTiles;
};