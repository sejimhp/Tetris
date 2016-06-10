#pragma once;

# include <Siv3D.hpp>

# include "Piece.h"

class Map{
public:
	Map();

	void update(std::shared_ptr<Effect> effect);
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
	void exitLine(std::shared_ptr<Effect> effect);
public:
	int block_counter;
	int back_counter;

	int lineFlag;
	int flagCounter;

	int score;
	int shiftAllCounter;
};