#include "Game.hpp"
#include<iostream>

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
        player.MovePlayer();
        for(auto& laser: player.projectiles){
            laser.Update();
        }
        DeleteInactiveProjectiles();

        for(auto& enemy : enemies){
            enemy.Update(player.GetPosition());
        }

        CheckCollision();
    }
}

void Game::InitGame()
{
    run = true;
    CreateEnemy(1, {100, 100});
    CreateEnemy(1, {200, 200});
    CreateEnemy(1, {300, 300});
}

void Game::CreateEnemy(int type, Vector2 position)
{
    enemies.push_back(Enemy(type, position));
}

void Game::Draw()
{
    player.Draw();
    for(auto& projectile : player.projectiles){
        projectile.Draw();
    }

    for(auto& enemy : enemies){
        enemy.Draw();
    }
}

void Game::HandleInputs()
{
   if(run)
    {
        player.HandleInput();
        
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
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

void Game::CheckCollision()
{
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