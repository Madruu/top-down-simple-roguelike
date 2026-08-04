#pragma once

#include "external/raytmx/raytmx.h"

class TileMap {
    public:
        TileMap();
        ~TileMap();
        void Draw();
    private:
        TmxMap *map;
        Camera2D camera;
        Rectangle viewPort;
};