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
	void set(Piece piece) { color = piece.getColor(); }

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

	//�����̂����蔻��
	bool checkLeft(std::vector<std::vector<Piece> > map);
	//�E���̂����蔻��
	bool checkRight(std::vector<std::vector<Piece> > map);
	//�����̂����蔻��
	bool checkBottom(std::vector<std::vector<Piece> > map);

	//�}�b�v�ɏ�������
	void overWrite(std::vector<std::vector<Piece> > map);
	
	std::vector<std::vector<Piece> > pieces;
private:
	int y, x;
	int fallCounter;
};