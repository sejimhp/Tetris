# include <Siv3D.hpp>
# include <memory>

# include "Game.h"
# include "Effect.h"

Game::Game(){
	back_counter = 0;

	map = std::make_shared < Map >() ;
	effect = std::make_shared < Effect >() ;
}

void Game::update(){
	map->update();

	back_counter++;
	if(back_counter %= 10){
		Vec2 pos(Random(640.0), Random(480.0));
		effect->add<Snow>(pos, 1);
	}
	effect->setSpeed(0.3);
	effect->update();
}

void Game::draw(){
	map->draw();
}