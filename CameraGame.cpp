#include "CameraGame.hpp"
#include <raylib.h>


CameraGame::CameraGame()
{
    camera.offset = {
        player.GetPosition()
    };
    camera.rotation = 0.0f;
    camera.target = { 0.0f, 0.0f };
    camera.zoom = 1.0f;
}

CameraGame::~CameraGame()
{

}

void CameraGame::Update(const Vector2& targetPosition)
{ 
    Vector2 playerTarget = {
        targetPosition.x + frameWidth / 2.0f,
        targetPosition.y + frameHeight / 2.0f
    };
    float dt = GetFrameTime();
    camera.target.x += (playerTarget.x - camera.target.x) * smoothSpeed * dt;
    camera.target.y += (playerTarget.y - camera.target.y) * smoothSpeed * dt;
}

void CameraGame::Begin()
{
    BeginMode2D(camera);
}

void CameraGame::End()
{
    EndMode2D();
}
    