#include "Player.hpp"
#include <raylib.h>
#include <raymath.h>
#include <cmath>
#include <iostream>

Player::Player()
{
        spr_player_sheet = LoadTexture("assets/spr_player1_Sheet.png");
        playerPos.x = GetScreenWidth() / 2;
        playerPos.y = GetScreenHeight() / 2;
        frameWidth = spr_player_sheet.width / totalFrames;
        frameHeight = spr_player_sheet.height;
        lastTimeFired = 0;
}

Player::~Player()
{
        UnloadTexture(spr_player_sheet);
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

void Player::MoveX()
{
        SaveX();
        playerPos.x += input.x * speed * GetFrameTime();
}

void Player::MoveY()
{
        SaveY();
        playerPos.y += input.y * speed * GetFrameTime();
}

void Player::Draw()
{
        frameTimer += GetFrameTime();

        if(frameTimer >= frameSpeed)
        {
                frameTimer = 0.0;
                currentFrame++;

                if(currentFrame >= totalFrames)
                {
                        currentFrame = 0;
                }
        }

        Rectangle srcRect = {
                static_cast<float>(currentFrame * frameWidth),
                0.0f,
                static_cast<float>(frameWidth),
                static_cast<float>(frameHeight)
        };
        
        DrawTextureRec(spr_player_sheet, srcRect, playerPos, WHITE);
}

void Player::FireProjectile()
{
        if(GetTime() - lastTimeFired >= 0.1)
        {
                Vector2 playerCenter = {
                        playerPos.x + frameWidth / 2,
                        playerPos.y + frameHeight / 2
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
                playerPos.x + frameWidth / 2,
                playerPos.y + frameHeight / 2
        };

        Vector2 direction;

        direction.x = mouseLocation.x - playerCenter.x;
        direction.y = mouseLocation.y - playerCenter.y;

        direction = Vector2Normalize(direction);

        return direction;
}
 
void Player::AttackSlash()
{
        Vector2 mousePosition = GetMouseAim();

        Vector2 playerCenter = {
                playerPos.x + frameWidth / 2,
                playerPos.y + frameHeight / 2
        };

        int slashInterval = 300;

        //slashes = SlashAttack(playerCenter, mousePosition, slashInterval);
        slashes.push_back(
                SlashAttack(playerCenter, mousePosition, slashInterval)
        );
}

Vector2 Player::GetCenter()
{
        return { playerPos.x + frameWidth / 2.0f, playerPos.y + frameHeight / 2.0f };
}

Vector2 Player::GetPosition() const
{
        return {
                playerPos.x + frameWidth / 2.0f,
                playerPos.y + frameHeight / 2.0f
        };
}

Rectangle Player::GetRect()
{
        return { playerPos.x, playerPos.y, static_cast<float>(frameWidth), static_cast<float>(frameHeight) };
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

void Player::SaveX()
{
        oldPlayerPosition.x = playerPos.x;
}

void Player::RestoreX()
{
        playerPos.x = oldPlayerPosition.x;
}

void Player::SaveY()
{
        oldPlayerPosition.y = playerPos.y;
}

void Player::RestoreY()
{
        playerPos.y = oldPlayerPosition.y;
}

void Player::KnockBack()
{   
        playerPos = Vector2Add(
                playerPos,
                Vector2Scale(knockBackVelocity, GetFrameTime())
        );

        // Decreases knockback
        knockBackVelocity = Vector2Scale(knockBackVelocity, 0.9f);
}