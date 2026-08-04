#include "Game.hpp"
#include <iostream>

Game::Game()
{
    InitGame();
}

Game::~Game()
{

}

void Game::Update()
{
    if(run)
    {
        player.MoveX();
        if(CheckCollisionWithTiles())
        {
            player.RestoreX();
        }
        player.MoveY();
        if(CheckCollisionWithTiles())
        {
            player.RestoreY();
        }

        camera.Update(player.GetCenter());

        for(auto& laser: player.projectiles){
            laser.Update();
        }
        DeleteInactiveProjectiles();

        for(auto& enemy : enemies){
            enemy.Update(player.GetPosition());
        }

        CheckCollisionWithEnemy();
        player.KnockBack();
    }
}

void Game::InitGame()
{
    run = true;
    collisionTiles.push_back({100, 100, 64, 64});
    
    //CreateEnemy(1, {100, 100});
    //CreateEnemy(1, {200, 200});
    //CreateEnemy(1, {300, 300});
}

void Game::CreateEnemy(int type, Vector2 position)
{
    enemies.push_back(Enemy(type, position));
}

void Game::Draw()
{   
    camera.Begin();
    tileMap.Draw();
    player.Draw();
    for(auto& projectile : player.projectiles){
        projectile.Draw();
    }

    for(auto& enemy : enemies){
        enemy.Draw();
    }

    for(auto& tile : collisionTiles) {
        DrawRectangleRec(tile, WHITE);
    }
    
    camera.End();
}

void Game::HandleInputs()
{
   if(run)
    {
        player.HandleInput();
        
        if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        {
            std::cout << "Projectile fired" << std::endl;
            player.FireProjectile();
            std::cout << player.projectiles.size() << std::endl;
        }
    }
}

void Game::DeleteInactiveProjectiles()
{
    for(auto it = player.projectiles.begin(); it != player.projectiles.end();){
        if(!it -> isActive)
        {
            it = player.projectiles.erase(it);
            std::cout << "Proj deleted" << std::endl;
        } else {
            ++it;
        }
    }
}

void Game::CheckCollisionWithEnemy()
{
    //Enemies
    for(auto& enemy : enemies) {
        Rectangle playerRect = player.GetRect();
        Rectangle enemyRect = enemy.GetRect();
        collided = CheckCollisionRecs(playerRect, enemyRect);
        if(collided)
        {
            boxCollision = GetCollisionRec(playerRect, enemyRect);
            std::cout << "Collided!" << std::endl;
            player.TakeDamage(2, enemy.GetEnemyPosition());
        }
    }
}

bool Game::CheckCollisionWithTiles()
{
    Rectangle playerBox = player.GetRect();
    for(auto& tile : collisionTiles) {
        collided = CheckCollisionRecs(playerBox, tile);
        if(collided)
        {
            return true;
        }
    }
    return false;
}