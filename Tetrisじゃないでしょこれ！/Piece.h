#pragma once;

# include <Siv3D.hpp>

class Piece{
public:
	enum color{
		BULE,
		RED, 
		ORANGE,
		GREENE
	};

	Piece();

	void update();
	void draw();

private:
public:
};

class Pieces{
public:
	Pieces();

	
	std::vector<std::vector<Piece> > pieces;
private:
};