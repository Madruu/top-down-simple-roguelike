#pragma once
#include <raylib.h>
class Enemy {
    public:
        Enemy(int type, Vector2 position);
        void Draw();
        void Update(const Vector2& position);
        int GetEnemyType() const;
        static void UnloadImages();
        Rectangle GetRect();

    private:
        int type;
        float moveSpeed = 200.0f;
        //int moveSpeed = 3;
        void FollowPlayer(const Vector2& playerPosition);
        Vector2 position;
        static Texture2D spr_enemies[3]; 
}; 