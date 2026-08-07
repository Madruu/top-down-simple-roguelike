#pragma once
#include <raylib.h>
class SlashAttack{
        public:
                SlashAttack() = default;
                SlashAttack(Vector2 slashPos, Vector2 slashDirection, int slashInterval);
                void Draw();
                void Update(const Vector2& playerCenter);
                Rectangle GetRect();
                bool isActive;

        private:
                Vector2 slashDirection;
                int slashInterval;
                Texture2D spr_slash;
                Vector2 slashPos;
                float distanceFromPlayer = 24.0f;
                int frameWidth = 128;
                int frameHeight = 32;
                float frameTimer = 0.0f;
                float frameSpeed = 0.03f;
                int totalFrames = 4;
                int currentFrame = 0;
};