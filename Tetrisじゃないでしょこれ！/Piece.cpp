# include <Siv3D.hpp>

# include "Piece.h"
# include "Map.h"
# include "Game.h"

Piece::Piece(){

}

void Piece::update(){

}

void Piece::draw(int x, int y){
	switch (color){
	case Type::BULE:
		Rect(x, y, BSIZE - 1, BSIZE - 1).draw({ Palette::Aqua, 80 });
		break;
	case Type::RED:
		Rect(x, y, BSIZE - 1, BSIZE - 1).draw({ Palette::Red, 80 });
		break;
	case Type::ORANGE:
		Rect(x, y, BSIZE - 1, BSIZE - 1).draw({ Palette::Orange, 80 });
		break;
	case Type::GREEN:
		Rect(x, y, BSIZE - 1, BSIZE - 1).draw({ Palette::Green, 80 });
		break;
	}
}

Pieces::Pieces(){
	pieces.resize(3);
	for (int i = 0; i < 3; i++){
		pieces[i].resize(3);
	}
	fallCounter = 0;
}

void Pieces::update(Game* game){
	std::shared_ptr<Map> MAP = game->getMap();
	std::vector<std::vector<Piece> > map = MAP->getMap();

	if (Input::KeyLeft.clicked && checkLeft(map)){
		x--;
	}
	if (Input::KeyRight.clicked && checkRight(map)){
		x++;
	}
	if (++fallCounter % 100 == 0 || Input::KeyDown.clicked){
		if (!checkBottom(map)){
			MAP->overWrite(pieces, x, y);
			newPiece();
		}
		y++;
	}

}

void Pieces::draw(){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			pieces[i][j].draw(40 + (x + j) * BSIZE, 20 + (y + i) * BSIZE);
		}
	}
}

void Pieces::newPiece(){
	//êŠ‚Æ’l‚Ì‰Šú‰»
	y = 0; x = 4;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			pieces[i][j].escape();
		}
	}

	//set
	Type t;
	switch (Random(1, 4)){
	case 1:
		t = Type::BULE;
		break;
	case 2:
		t = Type::RED;
		break;
	case 3:
		t = Type::ORANGE;
		break;
	case 4:
		t = Type::GREEN;
		break;
	}
	for (int i = 0; i < 4;){
		int X = Random(0, 2);
		int Y = Random(0, 2);
		if (pieces[Y][X].getColor() == Type::NUL){
			pieces[Y][X].setColor(t);
			i++;
		}
	}
}

bool Pieces::checkLeft(std::vector<std::vector<Piece> > map){
	int dy, dx;
	for (int j = 0; j < 3; j++){
		for (int i = 0; i < 3; i++){
			dx = x + j - 1;
			dy = y + i;
			if (pieces[i][j].getColor() != Type::NUL &&
				(dx < 0 || map[dy][dx].getColor() != Type::NUL)){
				return false;
			}
		}
	}
	return true;
}

bool Pieces::checkRight(std::vector<std::vector<Piece> > map){
	int dy, dx;
	for (int j = 2; j >= 0; j--){
		for (int i = 0; i < 3; i++){
			dx = x + j + 1;
			dy = y + i;
			if (pieces[i][j].getColor() != Type::NUL &&
				(dx >= 10 || map[dy][dx].getColor() != Type::NUL)){
				return false;
			}
		}
	}
	return true;
}

bool Pieces::checkBottom(std::vector<std::vector<Piece> > map){
	int dy, dx;
	for (int i = 2; i >= 0; i--){
		for (int j = 0; j < 3; j++){
			dx = x + j;
			dy = y + i + 1;
			if (pieces[i][j].getColor() != Type::NUL &&
				(dy >= 20 || map[dy][dx].getColor() != Type::NUL)){
				return false;
			}
		}
	}
	return true;
}
