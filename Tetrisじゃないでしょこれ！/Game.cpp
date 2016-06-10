# include <Siv3D.hpp>
# include <memory>

# include "Game.h"
# include "Effect.h"

Game::Game(){
	state = State::GAME;
	back_counter = 0;

	map = std::make_shared < Map >() ;
	pieces = std::make_shared < Pieces >() ;
	effect = std::make_shared < Effect >() ;
	pieces->newPiece();
}

void Game::update(){


	switch (state){
	case State::GAME:
		if (Input::KeySpace.clicked){
			pieces->newPiece();
		}

		map->update(getEffect());
		pieces->update(this);

		effect->setSpeed(0.3);
		effect->update();
		break;

	case State::GAMEOVER:
		if (Input::KeySpace.clicked){
			map->clear();
			pieces->newPiece();
			state = State::GAME;
		}
		break;
	}
}

void Game::draw(){
	static Font font(30);

	map->draw();
	pieces->draw();

	switch (state)
	{
	case State::GAMEOVER:
		font(L"GameOver").draw();
		break;
	}
}