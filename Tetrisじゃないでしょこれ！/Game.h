# pragma once

# include <Siv3D.hpp>

# include "Piece.h"
# include "Map.h"

class Map;

class Game{
public:
	Game();

	void update();
	void draw();

private:
	int back_counter;

	std::shared_ptr<Map> map;
	std::shared_ptr<Effect> effect;
public:

};