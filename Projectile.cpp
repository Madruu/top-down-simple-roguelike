#include "Projectile.hpp"
#include <iostream>
Projectile::Projectile(Vector2 position, Vector2 direction, int speed)
{
    this -> position = position;
    this -> direction = direction;
    this -> speed = speed;

    isActive = true;
}

void Projectile::Draw()
{
    //std::cout << "Draw is called" << std::endl;
    if(isActive)
    {
         std::cout << "Projectile pos: "
                  << position.x << ", "
                  << position.y << std::endl;
        DrawRectangle(position.x, position.y, 20, 20, {255, 255, 255, 255});
    }
}

void Projectile::Update()
{
    //position.x += speed;
    position.y += direction.y * speed;
    position.x += direction.x * speed;
    if(isActive)
    {
        if(position.y > GetScreenHeight() - 100 || position.y < 0)
        {
            std::cout << "is inactive" << std::endl;
            isActive = false;
        }
    }
}

Rectangle Projectile::GetRect()
{
    Rectangle rect;
    rect.x = position.x;
    rect.y = position.y;

    rect.width = 4;
    rect.height = 10;
    return rect;
}
