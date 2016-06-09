#pragma once

# include "Piece.h"

class Pieces{
public:
	Pieces();

	void update(Game* game);
	void draw();

	void newPiece();

	//左側のあたり判定
	bool checkLeft(std::vector<std::vector<Piece> > map);
	//右側のあたり判定
	bool checkRight(std::vector<std::vector<Piece> > map);
	//下側のあたり判定
	bool checkBottom(std::vector<std::vector<Piece> > map);

	//マップに書き込み
	void overWrite(std::vector<std::vector<Piece> > map);

	//回転
	void turn();
	
	std::vector<std::vector<Piece> > pieces;
private:
	int y, x;
	int fallCounter;
};