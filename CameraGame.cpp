#include "CameraGame.hpp"
#include <raylib.h>


CameraGame::CameraGame()
{
    camera.offset = {
        player.GetPosition()
    };
    camera.rotation = 0.0f;
    camera.target = { 0.0f, 0.0f };
    camera.zoom = 2.0f;
}

CameraGame::~CameraGame()
{

}

void CameraGame::Update(const Vector2& targetPosition)
{ 
    float dt = GetFrameTime();

    camera.target.x += (targetPosition.x - camera.target.x) * smoothSpeed * dt;
    camera.target.y += (targetPosition.y - camera.target.y) * smoothSpeed * dt;
}

void CameraGame::Begin()
{
    BeginMode2D(camera);
}

void CameraGame::End()
{
    EndMode2D();
}
    