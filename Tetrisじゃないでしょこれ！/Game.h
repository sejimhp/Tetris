# pragma once

# include <Siv3D.hpp>

# include "Pieces.h"
# include "Map.h"

class Map;

enum State{
	GAME,
	GAMEOVER
};

class Game{
public:
	Game();

	void update();
	void draw();

	std::shared_ptr<Map> getMap() const { return map; }
	std::shared_ptr<Effect> getEffect() const { return effect; }

	void setGameOver() { state = State::GAMEOVER; }

private:
	int back_counter;

	std::shared_ptr<Map> map;
	std::shared_ptr<Pieces> pieces;
	std::shared_ptr<Effect> effect;

	State state;
public:

};