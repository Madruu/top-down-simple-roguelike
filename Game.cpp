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
        for(auto& laser: player.projectiles){
            laser.Update();
        }
        DeleteInactiveProjectiles();
    }
}

void Game::InitGame()
{
    run = true;
}

void Game::Draw()
{
    player.Draw();
    for(auto& projectile : player.projectiles){
        projectile.Draw();
    }
}

void Game::HandleInputs()
{
   if(run)
    {
        player.MovePlayer();

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