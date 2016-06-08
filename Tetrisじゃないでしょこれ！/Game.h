# pragma once
# include <Siv3D.hpp>

#include "Piece.h"
#include "Map.h"

class Game{
public:
	Game();

	void update();
	void draw();

private:
	std::shared_ptr<Map> map;
public:
};