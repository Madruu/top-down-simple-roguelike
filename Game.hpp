#pragma once
#include "Player.hpp"
#include "Projectile.hpp"
#include "Enemy.hpp"
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
        Player player;
        bool run;
        std::vector<Enemy> CreateEnemy();
        std::vector<Enemy> enemies;
        //Vector2 FollowPlayer();
        //void moveEnemys();
        //void checkCollision();
        
};