#pragma once
#include "Player.hpp"
#include "Projectile.hpp"
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
        //std::vector<Enemy> CreateEnemy();
        //void moveEnemys();
        //void checkCollision();
        //std::vector<Eenemy> enemies;
};