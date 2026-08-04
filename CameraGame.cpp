#include "CameraGame.hpp"
#include <raylib.h>
#include <raymath.h>

CameraGame::CameraGame()
{
    camera.offset = {
        GetScreenWidth() / 2.0f,
        GetScreenHeight() / 2.0f
    };
    camera.rotation = 0.0f;
    camera.target = { 0.0f, 0.0f };
    camera.zoom = 2.0f;
}

CameraGame::~CameraGame()
{

}

void CameraGame::Update(const Vector2& playerPosition)
{
    float dt = GetFrameTime();

    Vector2 mouse = GetMousePosition();

    Vector2 screenCenter = {
        GetScreenWidth() / 2.0f,
        GetScreenHeight() / 2.0f
    };

    Vector2 mouseOffset = Vector2Subtract(mouse, screenCenter);

    float lookAhead = 0.10f;

    mouseOffset = Vector2Scale(mouseOffset, lookAhead);

    Vector2 desiredTarget = Vector2Add(playerPosition, mouseOffset);

    camera.target.x += (desiredTarget.x - camera.target.x) * smoothSpeed * dt;
    camera.target.y += (desiredTarget.y - camera.target.y) * smoothSpeed * dt;
}

void CameraGame::Begin()
{
    BeginMode2D(camera);
}

void CameraGame::End()
{
    EndMode2D();
}
    