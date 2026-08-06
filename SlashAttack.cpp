#include "SlashAttack.hpp"

SlashAttack::SlashAttack(Vector2 playerPos, Vector2 slashDirection, int slashInterval)
{
        this -> playerPos = playerPos;
        this -> slashDirection = slashDirection;
        this -> slashInterval = slashInterval;
        spr_slash = LoadTexture("assets/spr_attack1_Sheet.png");
}       

void SlashAttack::Draw()
{
        DrawTextureV(spr_slash, playerPos, WHITE);
}

void SlashAttack::Update()
{
        playerPos.x = slashDirection.x;
        playerPos.y = slashDirection.y;
}