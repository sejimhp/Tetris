# include <Siv3D.hpp>

# include "Piece.h"

Piece::Piece(){

}

void Piece::update(){

}

void Piece::draw(){

}

Pieces::Pieces(){

	pieces.resize(3);
	for (auto a : pieces){
		a.resize(3);
	}
}