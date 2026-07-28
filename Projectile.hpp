#pragma once
#include <raylib.h>
class Projectile {
    public:
        Projectile(Vector2 position, Vector2 direction, int projSpeed);
        void Draw();
        void Update(); 
        bool isActive;
        Rectangle GetRect();


    private:
        int speed;
        Vector2 position;
        Vector2 direction;
};
