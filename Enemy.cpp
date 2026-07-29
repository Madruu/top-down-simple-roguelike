#include "Enemy.hpp"
#include <raylib.h>
Texture2D spr_enemies[3] = {};


Enemy::Enemy(int type, Vector2 position, Vector2 target)
{
    this -> type = type;
    this -> position = position;
    this -> target = target;

    if(spr_enemies[type - 1].id == 0)
    {
        switch(type) {
            case 1:
                spr_enemies[0] = LoadTexture("assets/enemy1.png");
                break;
            case 2:
                spr_enemies[1] = LoadTexture("assets/enemy2.png");
                break;
            case 3:
                spr_enemies[2] = LoadTexture("assets/enemy3.png");
                break;
            default:
                spr_enemies[0] = LoadTexture("assets/enemy1.png");
        }
    }
};

