#pragma once

#include <raylib.h>

class SlashAttack{
        public:
                SlashAttack(Vector2 playerPos, Vector2 slashDirection, int slashInterval);
                void Draw();
                void Update();
                Rectangle GetRect();

        private:
                Vector2 slashDirection;
                int slashInterval;
                Texture2D spr_slash;
                Vector2 playerPos;

};