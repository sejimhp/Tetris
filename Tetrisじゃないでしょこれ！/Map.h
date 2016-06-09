#pragma once;

# include <Siv3D.hpp>

# include "Piece.h"

class Map{
public:
	Map();

	void update();
	void draw();
	std::vector<std::vector<Piece> > getMap() const { return map; }

private:
	std::vector<std::vector<Piece> > map;
public:
	int block_counter;
};