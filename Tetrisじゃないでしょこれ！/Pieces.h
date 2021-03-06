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

	//被っているところばゲーム終了とみなす
	bool over(std::vector<std::vector<Piece> > map);

	//回転
	void turn(std::vector<std::vector<Piece> > map);

	//入れ替え
	void swap1();
	void swap2();
	
private:
	std::vector<std::vector<Piece> > pieces;
	std::vector<std::vector<Piece> > next_pieces;
	std::vector<std::vector<Piece> > next_next_pieces;

	std::vector<std::vector<Piece> > hold1;
	std::vector<std::vector<Piece> > hold2;
	int y, x;
	int fallCounter;
};