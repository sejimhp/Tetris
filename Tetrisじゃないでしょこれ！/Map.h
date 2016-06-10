#pragma once;

# include <Siv3D.hpp>

# include "Piece.h"

class Map{
public:
	Map();

	void update();
	void draw();
	std::vector<std::vector<Piece> > getMap() const { return map; }

	void overWrite(std::vector<std::vector<Piece> > pieces, int x, int y);

	//全てNULで初期化
	void clear();

private:
	std::vector<std::vector<Piece> > map;

	//上からy番目, 左からxを下に 縦1列シフト
	void shiftDown(int y);
	//全部シフト!
	void shiftAll();

	//一列そろっているところがあれば消す
	void exitLine();
public:
	int block_counter;
};