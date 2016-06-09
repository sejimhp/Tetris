#pragma once;

# include <Siv3D.hpp>

# define HEIGHT 20
# define WIDTH 10
# define BSIZE 20

class Game;

enum Type{
	NUL,
	BULE,
	RED,
	ORANGE,
	GREEN
};

class Piece{
public:
	Piece();

	void update();
	void draw(int x, int y);

	void escape(){ color = NUL; }

	Type getColor() const { return color; }
	void setColor(Type t) { color = t; }

private:
	Type color;
public:
};

class Pieces{
public:
	Pieces();

	void update(Game* game);
	void draw();

	void newPiece();

	//ç∂ë§ÇÃÇ†ÇΩÇËîªíË
	bool checkLeft(std::vector<std::vector<Piece> > map);
	//âEë§ÇÃÇ†ÇΩÇËîªíË
	bool checkRight(std::vector<std::vector<Piece> > map);
	//â∫ë§ÇÃÇ†ÇΩÇËîªíË
	bool checkBottom(std::vector<std::vector<Piece> > map);
	
	std::vector<std::vector<Piece> > pieces;
private:
	int y, x;
	int fallCounter;
};