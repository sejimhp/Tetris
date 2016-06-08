# include <Siv3D.hpp>

# include "Map.h"

Map::Map(){
	block_counter = 0;

	map.resize(10);
	for (auto row: map){
		row.resize(10);
	}
}

void Map::update(){

}

void Map::draw(){

	//draw line
	Line(39, 20, 39, 20 + BSIZE*HEIGHT).draw();
	Line(40 + BSIZE*WIDTH, 20, 40 + BSIZE*WIDTH, 20 + BSIZE*HEIGHT).draw();
	Line(39, 20 + BSIZE*HEIGHT, 40 + BSIZE*WIDTH, 20 + BSIZE*HEIGHT).draw();

	//draw block
	for (int y = 0; y < HEIGHT; y++){
		for (int x = 0; x < WIDTH; x++){
			Rect(40 + BSIZE*x, 20 + BSIZE*y, 19, 19).draw({Palette::Gray, 50});
		}
	}
}