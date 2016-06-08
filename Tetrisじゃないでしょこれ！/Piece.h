#pragma once;

# include <Siv3D.hpp>
enum Type{
	NUL,
	BULE,
	RED,
	ORANGE,
	GREENE
};

class Piece{
public:
	Piece();

	void update();
	void draw();

	void escape(){ color = NUL; }

private:
	Type color;
public:
};

class Pieces{
public:
	Pieces();

	void newPiece();
	
	std::vector<std::vector<Piece> > pieces;
private:
};