#pragma once

# include "Piece.h"

class Pieces{
public:
	Pieces();

	void update(Game* game);
	void draw();

	void newPiece();

	//¶‘¤‚Ì‚ ‚½‚è”»’è
	bool checkLeft(std::vector<std::vector<Piece> > map);
	//‰E‘¤‚Ì‚ ‚½‚è”»’è
	bool checkRight(std::vector<std::vector<Piece> > map);
	//‰º‘¤‚Ì‚ ‚½‚è”»’è
	bool checkBottom(std::vector<std::vector<Piece> > map);

	//”í‚Á‚Ä‚¢‚é‚Æ‚±‚ë‚ÎƒQ[ƒ€I—¹‚Æ‚İ‚È‚·
	bool over(std::vector<std::vector<Piece> > map);

	//‰ñ“]
	void turn(std::vector<std::vector<Piece> > map);
	
	std::vector<std::vector<Piece> > pieces;
private:
	int y, x;
	int fallCounter;
};