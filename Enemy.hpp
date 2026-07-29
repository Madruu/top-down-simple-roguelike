#pragma once
#include <raylib.h>
class Enemy {
    public:
        Enemy(int type, Vector2 position, Vector2 target);
        ~Enemy();
        void Draw();
        void Update(Vector2 position);
        static Texture2D spr_enemies[3];
        int GetEnemyType();
        static void UnloadImages();
        Rectangle GetRect();
        int type;

    private:
        int type;
        Vector2 position;
        Vector2 target;
    
}; 