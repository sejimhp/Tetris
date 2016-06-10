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

	//�S��NUL�ŏ�����
	void clear();

private:
	std::vector<std::vector<Piece> > map;

	//�ォ��y�Ԗ�, ������x������ �c1��V�t�g
	void shiftDown(int y);
	//�S���V�t�g!
	void shiftAll();

	//��񂻂���Ă���Ƃ��낪����Ώ���
	void exitLine();
public:
	int block_counter;
};