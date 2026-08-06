#include "TileMap.hpp"
#include <iostream>
TileMap::TileMap()
{
        map = LoadTMX("tile/tileSetRogueLike2.tmx");
        camera = { 0 };
        camera.target = { 0.0f, 0.0f };
        camera.offset = { 0.0f, 0.0f };
        camera.zoom = 1.0f;
        camera.rotation = 0.0f;
        viewPort = { 100, 100, static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) };
}

TileMap::~TileMap()
{
        UnloadTMX(map);
}

void TileMap::Draw()
{
        DrawTMX(map, &camera, &viewPort, 0, 0, WHITE);
}
