#include "SlashAttack.hpp"
#include <iostream>
#include <raymath.h>
SlashAttack::SlashAttack(Vector2 slashPos, Vector2 slashDirection, int slashInterval)
{
        this -> slashPos = slashPos;
        this -> slashDirection = slashDirection;
        this -> slashInterval = slashInterval;
        spr_slash = LoadTexture("assets/spr_attack1_Sheet.png");
        frameWidth = spr_slash.width / totalFrames;
        frameHeight = spr_slash.height;
        isActive = true;
}       

void SlashAttack::Draw()
{       

        if (!isActive)
                return;

        Rectangle srcRect = {
                static_cast<float>(currentFrame * frameWidth),
                0.0f,
                static_cast<float>(frameWidth),
                static_cast<float>(frameHeight)
        };

        Rectangle destRect = {
                slashPos.x,
                slashPos.y,
                static_cast<float>(frameWidth),
                static_cast<float>(frameHeight)
        };

        Vector2 origin = {
                frameWidth / 2.0f,
                frameHeight / 2.0f
        };

        float angle = atan2f(slashDirection.y, slashDirection.x) * RAD2DEG;

        DrawTexturePro(
                spr_slash,
                srcRect,
                destRect,
                origin,
                angle,
                WHITE
        );
}

void SlashAttack::Update(const Vector2& playerCenter)
{
        float distance = 24.0f;

        slashPos = Vector2Add(
                playerCenter,
                Vector2Scale(slashDirection, distance)
        );

        frameTimer += GetFrameTime();

        if (frameTimer >= frameSpeed)
        {
                frameTimer = 0.0f;
                currentFrame++;

                if (currentFrame >= totalFrames)
                {
                 isActive = false;
                }
        }
}

Rectangle SlashAttack::GetRect()
{
        return {slashPos.x, slashPos.y, static_cast<float>(frameWidth), static_cast<float>(frameHeight) };
}