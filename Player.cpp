#include "Player.hpp"
#include "Projectile.hpp"
#include <raylib.h>
#include <raymath.h>
#include <cmath>
#include <iostream>

Player::Player()
{
    spr_player = LoadTexture("assets/spr_player_big.png");
    playerPos.x = GetScreenWidth() / 2;
    playerPos.y = GetScreenHeight() / 2;
    lastTimeFired = 0;
}

Player::~Player()
{
    UnloadTexture(spr_player);
}

void Player::MovePlayer()
{
   Vector2 input = { 0.0f, 0.0f };
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))    input.y -= 1.0f;
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))  input.y += 1.0f;
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))  input.x -= 1.0f;
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) input.x += 1.0f;

    float length = sqrtf(input.x * input.x + input.y * input.y);

    if (length > 0.0f) {
        input.x /= length;
        input.y /= length;
    }

    playerPos.x += input.x * speed * GetFrameTime();
    playerPos.y += input.y * speed * GetFrameTime();
}

void Player::Draw()
{
    DrawTextureV(spr_player, playerPos, WHITE);
}

/*void Player::FireProjectile()
{
    if(GetTime() - lastTimeFired >= 0.1)
    {
        projectiles.push_back(Projectile({ playerPos.x ,playerPos.y }, GetMouseAim(), 30));
        lastTimeFired = GetTime();
    }
}*/
void Player::FireProjectile()
{
    if(GetTime() - lastTimeFired >= 0.1)
    {
        Vector2 playerCenter = {
            playerPos.x + spr_player.width / 2,
            playerPos.y + spr_player.height / 2
        };

        projectiles.push_back(
            Projectile(playerCenter, GetMouseAim(), 30)
        );

        lastTimeFired = GetTime();
    }
}
/*Vector2 Player::GetMouseAim()
{
   Vector2 mouseLocation = GetMousePosition();
   Vector2 direction;
   direction.x = mouseLocation.x - playerPos.x;
   direction.y = mouseLocation.y - playerPos.y;
   direction = Vector2Normalize(direction);
   std::cout << direction.x << "," << direction.y << std::endl;
   return direction;
    //return mouseLocation;
}*/

Vector2 Player::GetMouseAim()
{
    Vector2 mouseLocation = GetMousePosition();

    Vector2 playerCenter = {
        playerPos.x + spr_player.width / 2,
        playerPos.y + spr_player.height / 2
    };

    Vector2 direction;

    direction.x = mouseLocation.x - playerCenter.x;
    direction.y = mouseLocation.y - playerCenter.y;

    direction = Vector2Normalize(direction);

    return direction;
}
