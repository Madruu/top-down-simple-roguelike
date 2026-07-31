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

void Player::HandleInput()
{
    input = { 0.0f, 0.0f };
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))    input.y -= 1.0f;
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))  input.y += 1.0f;
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))  input.x -= 1.0f;
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) input.x += 1.0f;

    //Normalize vector
    float length = sqrtf(input.x * input.x + input.y * input.y);

    if (length > 0.0f) {
        input.x /= length;
        input.y /= length;
    }
}

void Player::MovePlayer()
{
    //Save position
    SavePosition();

    // Keyboard Movement
    playerPos.x += input.x * speed * GetFrameTime();
    playerPos.y += input.y * speed * GetFrameTime();

    // Knockback movement
     playerPos = Vector2Add(
        playerPos,
        Vector2Scale(knockBackVelocity, GetFrameTime())
    );

    // Decreases knockback
    knockBackVelocity = Vector2Scale(knockBackVelocity, 0.9f);
}

void Player::SavePosition()
{
    oldPlayerPosition = playerPos;
}

void Player::RestorePosition()
{
    playerPos = oldPlayerPosition;
}

void Player::Draw()
{
    DrawTextureV(spr_player, playerPos, WHITE);
}

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

Vector2 Player::GetPosition() const
{
    return {
        playerPos.x + spr_player.width / 2,
        playerPos.y + spr_player.height / 2
    };
}


Rectangle Player::GetRect()
{
    return { playerPos.x, playerPos.y, static_cast<float>(spr_player.width), static_cast<float>(spr_player.height)};
}

void Player::TakeDamage(int damage, const Vector2& enemySourcePosition)
{
    //Taking damage
    health -= damage;

    //Knockback
    Vector2 direction = { 
        playerPos.x - enemySourcePosition.x,
        playerPos.y - enemySourcePosition.y
    };
 
    direction = Vector2Normalize(direction);
    knockBackVelocity = Vector2Scale(direction, knockBackPower); // Basically just direction * knockbackPower
}