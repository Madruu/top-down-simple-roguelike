#include "Enemy.hpp"
#include <raylib.h>
#include <raymath.h>
Texture2D Enemy::spr_enemies[3] = {};


Enemy::Enemy(int type, Vector2 position)
{
    this -> type = type;
    this -> position = position;

    if(spr_enemies[type - 1].id == 0)
    {
        switch(type) {
            case 1:
                spr_enemies[0] = LoadTexture("assets/spr_enemy_1.png");
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

void Enemy::Draw()
{
    DrawTextureV(spr_enemies[type - 1], position, WHITE);
}

void Enemy::Update(const Vector2& playerPosition)
{
    FollowPlayer(playerPosition);
}

void Enemy::FollowPlayer(const Vector2& playerPosition)
{
    Vector2 direction;

    direction = {
        playerPosition.x - position.x,
        playerPosition.y - position.y
    };
    direction = Vector2Normalize(direction);
    
    position = Vector2Add(position, Vector2Scale(direction, moveSpeed * GetFrameTime()));
}

Rectangle Enemy::GetRect()
{
    return { position.x, position.y, static_cast<float>(spr_enemies[type - 1].width), static_cast<float>(spr_enemies[type - 1].height)};
}