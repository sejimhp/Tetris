#pragma once;

# include <Siv3D.hpp>

# include "Piece.h"

# define HEIGHT 20
# define WIDTH 10
# define BSIZE 20

class Map{
public:
	Map();

	void update();
	void draw();
private:
	std::vector<std::vector<Piece> > map;
public:
	int block_counter;
};