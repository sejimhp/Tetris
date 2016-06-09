#pragma once

# include "Piece.h"

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

	//��]
	void turn();
	
	std::vector<std::vector<Piece> > pieces;
private:
	int y, x;
	int fallCounter;
};