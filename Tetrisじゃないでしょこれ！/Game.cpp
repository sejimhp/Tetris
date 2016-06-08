# include <Siv3D.hpp>
# include <memory>

# include "Game.h"

Game::Game(){
	map = std::make_shared < Map >() ;
}

void Game::update(){
	map->update();
}

void Game::draw(){
	map->draw();
}