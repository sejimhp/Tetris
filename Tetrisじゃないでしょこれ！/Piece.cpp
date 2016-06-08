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

void Pieces::newPiece(){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			pieces[i][j].escape();
		}
	}

}