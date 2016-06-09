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
